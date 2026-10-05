`timescale 1ns/1ps

// ============================================================================
// MobileNetV2 71-op reference engine
// Model: mobilenetv2_a035_224_int8.tflite
// Target: Vivado 2018.1 / Verilog-2001
//
// This is a correctness-first reference implementation for simulation and
// initial synthesis/resource estimation. It is intentionally not the final
// high-performance FPGA architecture.
//
// Model semantics are taken from the exported TFLite graph:
//   - exact tensor shapes / zero points
//   - per-channel INT8 weights
//   - INT32 biases
//   - TFLite-style quantized multiplier rounding
//   - model-derived explicit PAD values
//   - model-derived fused RELU6 operations
//   - residual ADD rescaling
//
// Memory files are relative to the XSim working directory. For the supplied
// Vivado project layout the default below is correct.
// ============================================================================

`ifndef MNV2_MEM_DIR
`define MNV2_MEM_DIR "../../../../generated/"
`endif

module mnv2_71layer_ref #(
    parameter integer ACT_BYTES   = 4146912,
    parameter integer CONST_BYTES = 1694264,
    parameter integer DEBUG       = 0
)(
    input  wire       clk,
    input  wire       rst,
    input  wire       start,
    output reg        busy,
    output reg        done,
    output reg [9:0]  class_index
);

`include "../generated/model_params.vh"
`include "../generated/op_weight_meta.vh"
`include "../generated/op_quant_meta.vh"

    // ------------------------------------------------------------------------
    // Model memories
    // ------------------------------------------------------------------------
    reg signed [7:0] act_mem   [0:ACT_BYTES-1];
    reg        [7:0] const_mem [0:CONST_BYTES-1];

    reg signed [31:0] mult_mem [0:8039];
    reg signed [7:0]  shift_mem[0:8039];

    reg signed [31:0] add_m0[0:9];
    reg signed [31:0] add_m1[0:9];
    reg signed [7:0]  add_s0[0:9];
    reg signed [7:0]  add_s1[0:9];

    reg [31:0] tensor_base[0:179];
    reg [31:0] buffer_base[0:181];

    // ------------------------------------------------------------------------
    // Load generated model data.
    // ------------------------------------------------------------------------
    initial begin
        $readmemh("../../../../generated/constants.hex",   const_mem);
        $readmemh("../../../../generated/mult.mem",        mult_mem);
        $readmemh("../../../../generated/shift.mem",       shift_mem);
        $readmemh("../../../../generated/add_m0.mem",      add_m0);
        $readmemh("../../../../generated/add_m1.mem",      add_m1);
        $readmemh("../../../../generated/add_s0.mem",      add_s0);
        $readmemh("../../../../generated/add_s1.mem",      add_s1);
        $readmemh("../../../../generated/image.hex",       act_mem, 0, 150527);
        $readmemh("../../../../generated/tensor_base.mem", tensor_base);
        $readmemh("../../../../generated/buffer_base.mem", buffer_base);
    
        #1;
    
        $display("==============================================");
        $display("IMAGE MEMORY CHECK");
        $display("==============================================");
    
        $display("act_mem[0] = %h", act_mem[0]);
        $display("act_mem[1] = %h", act_mem[1]);
        $display("act_mem[2] = %h", act_mem[2]);
        $display("act_mem[3] = %h", act_mem[3]);
        $display("act_mem[4] = %h", act_mem[4]);
        $display("act_mem[5] = %h", act_mem[5]);
    
        $display("==============================================");
    end

    // ------------------------------------------------------------------------
    // Saturate to signed INT8.
    // ------------------------------------------------------------------------
    function automatic signed [7:0] sat8;
        input signed [63:0] x;
        begin
            if (x > 64'sd127)
                sat8 = 8'sd127;
            else if (x < -64'sd128)
                sat8 = -8'sd128;
            else
                sat8 = x[7:0];
        end
    endfunction

    // ------------------------------------------------------------------------
    // Exact TFLite/gemmlowp-style rounding divide by power of two.
    // This is important for negative accumulators; a simple arithmetic shift
    // is NOT equivalent to TFLite's RoundingDivideByPOT.
    // ------------------------------------------------------------------------
    function automatic signed [95:0] rounding_divide_by_pot;
        input signed [95:0] x;
        input integer exponent;
        reg signed [95:0] mask;
        reg signed [95:0] remainder;
        reg signed [95:0] threshold;
        reg signed [95:0] base;
        begin
            if (exponent <= 0) begin
                rounding_divide_by_pot = x;
            end
            else begin
                mask      = (96'sd1 <<< exponent) - 96'sd1;
                remainder = x & mask;
                threshold = (mask >>> 1) + ((x < 0) ? 96'sd1 : 96'sd0);
                base      = x >>> exponent;
                rounding_divide_by_pot = base +
                                         ((remainder > threshold) ? 96'sd1 : 96'sd0);
            end
        end
    endfunction

    // ------------------------------------------------------------------------
    // SaturatingRoundingDoublingHighMul equivalent.
    // The model's quantized multipliers are positive Q31 multipliers.
    // ------------------------------------------------------------------------
    function automatic signed [95:0] sr_doubling_high_mul;
        input signed [63:0] x;
        input signed [31:0] m;
        reg signed [95:0] product;
        reg signed [95:0] nudge;
        reg signed [95:0] q;
        begin
            product = x * m;
            if (product >= 0)
                nudge = 96'sd1073741824;       // 2^30
            else
                nudge = -96'sd1073741823;      // 1 - 2^30

            // Verilog signed division truncates toward zero, matching the
            // integer division used by the reference arithmetic.
            q = (product + nudge) / 96'sd2147483648; // 2^31
            sr_doubling_high_mul = q;
        end
    endfunction

    // ------------------------------------------------------------------------
    // TFLite MultiplyByQuantizedMultiplier.
    // shift is the exponent produced by QuantizeMultiplier.
    // ------------------------------------------------------------------------
    function automatic signed [63:0] requant;
        input signed [63:0] x;
        input signed [31:0] m;
        input signed [7:0]  sh;
        reg signed [95:0] q;
        begin
            q = sr_doubling_high_mul(x, m);

            if (sh > 0) begin
                q = q <<< sh;
            end
            else if (sh < 0) begin
                q = rounding_divide_by_pot(q, -sh);
            end

            requant = q[63:0];
        end
    endfunction

    // ------------------------------------------------------------------------
    // State / loop variables
    // ------------------------------------------------------------------------
    integer op;
    integer i;
    integer j;
    integer k;
    integer iy;
    integer ix;
    integer oi;
    integer ii;

    integer in_t;
    integer out_t;
    integer ih;
    integer iw;
    integer icn;
    integer oh;
    integer ow;
    integer ocn;
    integer ks;
    integer st;

    integer py;
    integer px;
    integer total_pad_h;
    integer total_pad_w;
    integer pad_h_before;
    integer pad_w_before;

    integer pad_top;
    integer pad_bottom;
    integer pad_left;
    integer pad_right;

    integer in_base;
    integer out_base;
    integer w_base;
    integer in_len;
    integer out_len;
    integer b_base;
    integer mb;
    integer pad_value;
    integer relu_max;

    reg signed [63:0] acc;
    reg signed [63:0] score;
    reg signed [63:0] best_score;
    reg signed [31:0] bias_word;
    reg [9:0] best_idx;

    localparam [3:0] IDLE = 4'd0;
    localparam [3:0] RUN  = 4'd1;
    localparam [3:0] ARG  = 4'd2;
    localparam [3:0] FIN  = 4'd3;

    reg [3:0] state;

    // ------------------------------------------------------------------------
    // Performance instrumentation
    //
    // IMPORTANT:
    // This correctness-first reference engine executes the nested MAC loops
    // inside a single Verilog always block. Therefore one completed operator
    // corresponds to one simulation clock interval in this architecture.
    // These counters report the actual RTL simulation clock cycles consumed
    // by this reference engine, not a cycle-accurate pipelined FPGA MAC
    // implementation.
    // ------------------------------------------------------------------------
    integer total_cycles;
    integer op_start_cycle;
    integer op_cycles;
    integer current_op;
    integer conv_count;
    integer dw_count;
    integer add_count;
    integer pad_count;
    integer mean_count;
    integer fc_count;
    integer quant_count;
    integer softmax_count;
    integer dequant_count;
    integer total_mac_ops;

    // Per-op cycle storage. 71 operators in the exported graph.
    integer op_start_cycles [0:70];
    integer op_end_cycles   [0:70];
    integer op_cycle_count  [0:70];

    // ------------------------------------------------------------------------
    // Main reference engine
    // ------------------------------------------------------------------------
    always @(posedge clk) begin
        if (rst) begin
            busy        <= 1'b0;
            done        <= 1'b0;
            class_index <= 10'd0;
            state       <= IDLE;
            op          <= 0;
            i           <= 0;
            best_score  <= -64'sh7fffffffffffffff;
            best_idx    <= 10'd0;

            total_cycles <= 0;
            op_start_cycle <= 0;
            op_cycles <= 0;
            current_op <= 0;
            conv_count <= 0;
            dw_count <= 0;
            add_count <= 0;
            pad_count <= 0;
            mean_count <= 0;
            fc_count <= 0;
            quant_count <= 0;
            softmax_count <= 0;
            dequant_count <= 0;
            total_mac_ops <= 0;
        end
        else begin
            done <= 1'b0;

            // Global simulation clock counter.
            total_cycles <= total_cycles + 1;

            case (state)
                IDLE: begin
                    busy <= 1'b0;

                    if (start) begin
                        busy  <= 1'b1;
                        op    <= 0;
                        state <= RUN;

                        // Performance measurement starts with OP 0.
                        op_start_cycle <= total_cycles + 1;
                        current_op <= 0;

                        // Reset performance counters.
                        conv_count <= 0;
                        dw_count <= 0;
                        add_count <= 0;
                        pad_count <= 0;
                        mean_count <= 0;
                        fc_count <= 0;
                        quant_count <= 0;
                        softmax_count <= 0;
                        dequant_count <= 0;
                        total_mac_ops <= 0;

                        // Model input:
                        // tensor 0  = UINT8, scale = 1/127.5, zp = 127
                        // tensor 109 = INT8,  same scale, zp = -1
                        // Therefore q109 = q0 - 128 exactly.
                        for (i = 0; i < 224*224*3; i = i + 1) begin
                            act_mem[tensor_base[109] + i] <=
                                $signed({1'b0, act_mem[tensor_base[0] + i]}) - 128;
                        end
                    end
                end

                RUN: begin
                    // Record the clock at which this operator starts.
                    op_start_cycles[op] = total_cycles;
                    op_start_cycle = total_cycles;

                    in_t     = op_in0(op);
                    out_t    = op_out(op);
                    ih       = t_h(in_t);
                    iw       = t_w(in_t);
                    icn      = t_c(in_t);
                    oh       = t_h(out_t);
                    ow       = t_w(out_t);
                    ocn      = t_c(out_t);
                    in_base  = tensor_base[in_t];
                    out_base = tensor_base[out_t];

                    // ========================================================
                    // CONV / DEPTHWISE CONV / FULLY CONNECTED
                    // ========================================================
                    if ((op_kind(op) == OP_CONV) ||
                        (op_kind(op) == OP_DW)   ||
                        (op_kind(op) == OP_FC)) begin

                        // Generated offsets point directly into constants.hex.
                        w_base = op_wbase(op);
                        b_base = op_bbase(op);

                        // ----------------------------------------------------
                        // Fully connected
                        // ----------------------------------------------------
                        if (op_kind(op) == OP_FC) begin
                            // IMPORTANT:
                            // TFLite represents the FC input/output tensors here
                            // as rank-2 tensors:
                            //
                            //   tensor 176 = [1, 1280]
                            //   tensor 177 = [1, 1000]
                            //
                            // The generated model_params.vh stores these flattened
                            // dimensions as:
                            //
                            //   t_h(176)=1280, t_w(176)=1, t_c(176)=1
                            //   t_h(177)=1000, t_w(177)=1, t_c(177)=1
                            //
                            // Therefore t_c() MUST NOT be used as the FC vector
                            // length. The old implementation only processed one
                            // input and generated one output, leaving FC[1..999]
                            // as X.
                            in_len  = t_h(in_t)  * t_w(in_t)  * t_c(in_t);
                            out_len = t_h(out_t) * t_w(out_t) * t_c(out_t);

                            for (oi = 0; oi < out_len; oi = oi + 1) begin
                                bias_word = $signed({
                                    const_mem[b_base + oi*4 + 3],
                                    const_mem[b_base + oi*4 + 2],
                                    const_mem[b_base + oi*4 + 1],
                                    const_mem[b_base + oi*4 + 0]
                                });

                                acc = bias_word;

                                for (ii = 0; ii < in_len; ii = ii + 1) begin
                                    acc = acc +
                                        ($signed(act_mem[in_base + ii]) - t_zp(in_t)) *
                                        $signed(const_mem[w_base + oi*in_len + ii]);
                                    total_mac_ops = total_mac_ops + 1;
                                end

                                mb = op_mbase(op) + oi;
                                score = requant(acc, mult_mem[mb], shift_mem[mb]) +
                                        t_zp(out_t);
                                act_mem[out_base + oi] <= sat8(score);
                            end
                        end

                        // ----------------------------------------------------
                        // CONV / DEPTHWISE CONV
                        // ----------------------------------------------------
                        else begin
                            ks = op_w_k(op);
                            st = op_stride(op);

                            // TFLite SAME uses:
                            //   total_pad = max(0, (out-1)*stride + kernel - in)
                            //   pad_before = floor(total_pad/2)
                            // and the remaining padding goes to bottom/right.
                            total_pad_h = (oh - 1) * st + ks - ih;
                            total_pad_w = (ow - 1) * st + ks - iw;
                            if (total_pad_h < 0) total_pad_h = 0;
                            if (total_pad_w < 0) total_pad_w = 0;

                            pad_h_before = total_pad_h / 2;
                            pad_w_before = total_pad_w / 2;

                            for (iy = 0; iy < oh; iy = iy + 1) begin
                                for (ix = 0; ix < ow; ix = ix + 1) begin
                                    for (oi = 0; oi < ocn; oi = oi + 1) begin

                                        bias_word = $signed({
                                            const_mem[b_base + oi*4 + 3],
                                            const_mem[b_base + oi*4 + 2],
                                            const_mem[b_base + oi*4 + 1],
                                            const_mem[b_base + oi*4 + 0]
                                        });

                                        acc = bias_word;

                                        for (j = 0; j < ks; j = j + 1) begin
                                            for (k = 0; k < ks; k = k + 1) begin
                                                py = iy * st + j - pad_h_before;
                                                px = ix * st + k - pad_w_before;

                                                if ((py >= 0) && (py < ih) &&
                                                    (px >= 0) && (px < iw)) begin

                                                    if (op_kind(op) == OP_DW) begin
                                                        // TFLite depthwise filter layout:
                                                        // [1, K, K, input_channels]
                                                        ii = oi;
                                                        acc = acc +
                                                            ($signed(act_mem[
                                                                in_base +
                                                                ((py*iw + px)*icn) + ii
                                                            ]) - t_zp(in_t)) *
                                                            $signed(const_mem[
                                                                w_base +
                                                                ((j*ks + k)*icn) + ii
                                                            ]);
                                                        total_mac_ops = total_mac_ops + 1;
                                                    end
                                                    else begin
                                                        // TFLite Conv2D filter layout:
                                                        // [out_channels, K, K, in_channels]
                                                        for (ii = 0; ii < icn; ii = ii + 1) begin
                                                            acc = acc +
                                                                ($signed(act_mem[
                                                                    in_base +
                                                                    ((py*iw + px)*icn) + ii
                                                                ]) - t_zp(in_t)) *
                                                                $signed(const_mem[
                                                                    w_base +
                                                                    (((oi*ks + j)*ks + k)*icn) + ii
                                                                ]);
                                                            total_mac_ops = total_mac_ops + 1;
                                                        end
                                                    end
                                                end
                                                // Outside the image the input is the
                                                // quantized representation of real 0,
                                                // so (input_q - input_zp) = 0 and there
                                                // is intentionally no MAC contribution.
                                            end
                                        end

                                        mb = op_mbase(op) + oi;
                                        score = requant(acc, mult_mem[mb], shift_mem[mb]) +
                                                t_zp(out_t);

                                        // Model-derived fused activation.
                                        if (op_has_relu6(op)) begin
                                            if (score < t_zp(out_t))
                                                score = t_zp(out_t);

                                            relu_max = op_relu6_max(op);
                                            if (score > relu_max)
                                                score = relu_max;
                                        end

                                        act_mem[out_base +
                                                ((iy*ow + ix)*ocn) + oi] <=
                                            sat8(score);
                                    end
                                end
                            end
                        end
                    end

                    // ========================================================
                    // EXPLICIT TFLITE PAD
                    // ========================================================
                    else if (op_kind(op) == OP_PAD) begin
                        // These values are generated from the actual TFLite
                        // PAD tensor, not guessed from the output dimensions.
                        pad_top    = op_pad_top(op);
                        pad_bottom = op_pad_bottom(op);
                        pad_left   = op_pad_left(op);
                        pad_right  = op_pad_right(op);

                        pad_value = t_zp(in_t);

                        for (iy = 0; iy < oh; iy = iy + 1) begin
                            for (ix = 0; ix < ow; ix = ix + 1) begin
                                for (oi = 0; oi < ocn; oi = oi + 1) begin

                                    if ((iy >= pad_top) &&
                                        (iy < ih + pad_top) &&
                                        (ix >= pad_left) &&
                                        (ix < iw + pad_left)) begin

                                        act_mem[out_base +
                                                ((iy*ow + ix)*ocn) + oi] <=
                                            act_mem[in_base +
                                                    (((iy-pad_top)*iw +
                                                      (ix-pad_left))*icn) + oi];
                                    end
                                    else begin
                                        act_mem[out_base +
                                                ((iy*ow + ix)*ocn) + oi] <=
                                            sat8(pad_value);
                                    end
                                end
                            end
                        end
                    end

                    // ========================================================
                    // QUANTIZED ADD / RESIDUAL CONNECTION
                    // ========================================================
                    else if (op_kind(op) == OP_ADD) begin
                        mb = add_slot(op);

                        for (i = 0; i < oh*ow*ocn; i = i + 1) begin
                            acc = requant(
                                $signed(act_mem[tensor_base[op_in0(op)] + i]) -
                                t_zp(op_in0(op)),
                                add_m0[mb], add_s0[mb]
                            );

                            acc = acc + requant(
                                $signed(act_mem[tensor_base[op_in1(op)] + i]) -
                                t_zp(op_in1(op)),
                                add_m1[mb], add_s1[mb]
                            ) + t_zp(out_t);

                            act_mem[out_base + i] <= sat8(acc);
                        end
                    end

                    // ========================================================
                    // GLOBAL AVERAGE POOLING / MEAN
                    // ========================================================
                    else if (op_kind(op) == OP_MEAN) begin
                        // Tensor 175 is [1,7,7,1280].
                        // Tensor 176 is the rank-2 tensor [1,1280].
                        //
                        // model_params.vh represents tensor 176 as
                        //   t_h=1280, t_w=1, t_c=1
                        // so using ocn=t_c(out_t) here would process only one
                        // channel. Explicitly use the flattened output length.
                        out_len = t_h(out_t) * t_w(out_t) * t_c(out_t);

                        for (oi = 0; oi < out_len; oi = oi + 1) begin
                            acc = 0;

                            for (i = 0; i < ih*iw; i = i + 1) begin
                                acc = acc +
                                    ($signed(act_mem[in_base + i*icn + oi]) -
                                     t_zp(in_t));
                            end

                            // TFLite integer rounding for this model's 7x7 mean.
                            // The scale is unchanged, so only division by 49 is needed.
                            if (acc >= 0)
                                acc = (acc + 24) / 49;
                            else
                                acc = (acc - 24) / 49;

                            score = acc + t_zp(out_t);
                            act_mem[out_base + oi] <= sat8(score);
                        end
                    end

                    // ========================================================
                    // SOFTMAX / DEQUANTIZE
                    // ========================================================
                    else if ((op_kind(op) == OP_SOFTMAX) ||
                             (op_kind(op) == OP_DEQUANT)) begin
                        // For classification, softmax and dequantization do not
                        // change the argmax. The reference therefore preserves
                        // the values and performs argmax on tensor 177.
                        for (i = 0; i < oh*ow*ocn; i = i + 1)
                            act_mem[out_base + i] <= act_mem[in_base + i];
                    end

                    // ========================================================
                    // QUANTIZE
                    // ========================================================
                    else if (op_kind(op) == OP_QUANT) begin
                        for (i = 0; i < oh*ow*ocn; i = i + 1)
                            act_mem[out_base + i] <=
                                $signed({1'b0, act_mem[in_base + i]}) - 128;
                    end

                    // --------------------------------------------------------
                    // Performance instrumentation for this completed operator.
                    // --------------------------------------------------------
                    op_end_cycles[op] = total_cycles;
                    op_cycle_count[op] = op_end_cycles[op] - op_start_cycles[op] + 1;

                    // Count operator classes.
                    if (op_kind(op) == OP_CONV) conv_count = conv_count + 1;
                    else if (op_kind(op) == OP_DW) dw_count = dw_count + 1;
                    else if (op_kind(op) == OP_ADD) add_count = add_count + 1;
                    else if (op_kind(op) == OP_PAD) pad_count = pad_count + 1;
                    else if (op_kind(op) == OP_MEAN) mean_count = mean_count + 1;
                    else if (op_kind(op) == OP_FC) fc_count = fc_count + 1;
                    else if (op_kind(op) == OP_QUANT) quant_count = quant_count + 1;
                    else if (op_kind(op) == OP_SOFTMAX) softmax_count = softmax_count + 1;
                    else if (op_kind(op) == OP_DEQUANT) dequant_count = dequant_count + 1;

                    if (DEBUG != 0) begin
                        if (op_kind(op) == OP_FC) begin
                            $display("MNV2 OP %0d complete, type=%0d, out_tensor=%0d, cycles=%0d, FC_IN=%0d, FC_OUT=%0d",
                                     op, op_kind(op), out_t, op_cycle_count[op], in_len, out_len);
                        end
                        else if (op_kind(op) == OP_MEAN) begin
                            $display("MNV2 OP %0d complete, type=%0d, out_tensor=%0d, cycles=%0d, MEAN_OUT=%0d",
                                     op, op_kind(op), out_t, op_cycle_count[op], out_len);
                        end
                        else begin
                            $display("MNV2 OP %0d complete, type=%0d, out_tensor=%0d, cycles=%0d",
                                     op, op_kind(op), out_t, op_cycle_count[op]);
                        end
                    end

                    // Op 68 is FC. Ops 69 and 70 do not change argmax.
                    if (op == 68) begin
                        // ----------------------------------------------------
                        // Complete performance report.
                        // ----------------------------------------------------
                        $display("");
                        $display("============================================================");
                        $display("MobileNetV2 RTL PERFORMANCE REPORT");
                        $display("============================================================");
                        $display("Total operator cycles : %0d", total_cycles);
                        $display("Total MAC operations  : %0d", total_mac_ops);
                        $display("");
                        $display("Operator timing:");
                        for (current_op = 0; current_op <= 68; current_op = current_op + 1) begin
                            $display("  OP %0d : start=%0d end=%0d cycles=%0d type=%0d out_tensor=%0d",
                                     current_op,
                                     op_start_cycles[current_op],
                                     op_end_cycles[current_op],
                                     op_cycle_count[current_op],
                                     op_kind(current_op),
                                     op_out(current_op));
                        end
                        $display("");
                        $display("Operator counts:");
                        $display("  CONV2D    : %0d", conv_count);
                        $display("  DEPTHWISE : %0d", dw_count);
                        $display("  ADD       : %0d", add_count);
                        $display("  PAD       : %0d", pad_count);
                        $display("  MEAN      : %0d", mean_count);
                        $display("  FC        : %0d", fc_count);
                        $display("  QUANTIZE  : %0d", quant_count);
                        $display("  SOFTMAX   : %0d", softmax_count);
                        $display("  DEQUANT   : %0d", dequant_count);
                        $display("============================================================");
                        $display("");

                        state      <= ARG;
                        i          <= 0;
                        best_score <= -64'sh7fffffffffffffff;
                        best_idx   <= 10'd0;
                    end
                    else begin
                        op <= op + 1;
                    end
                end

                // ============================================================
                // ARGMAX OF QUANTIZED FC OUTPUT
                // ============================================================
                ARG: begin
                    score = $signed(act_mem[tensor_base[177] + i]);

                    if ((DEBUG != 0) && (i < 10)) begin
                        $display("FC[%0d] = %0d", i, score);
                    end

                    if (i == 999) begin
                        if (score > best_score)
                            class_index <= i[9:0];
                        else
                            class_index <= best_idx;

                        state <= FIN;
                    end
                    else begin
                        if (score > best_score) begin
                            best_score <= score;
                            best_idx   <= i[9:0];
                        end
                        i <= i + 1;
                    end
                end

                FIN: begin
                    busy  <= 1'b0;
                    done  <= 1'b1;

                    $display("");
                    $display("============================================================");
                    $display("FINAL END-TO-END TIMING");
                    $display("============================================================");
                    $display("Total RTL cycles including ARGMAX : %0d", total_cycles);
                    $display("Total MAC operations              : %0d", total_mac_ops);
                    $display("Predicted class                   : %0d", class_index);
                    $display("============================================================");
                    $display("");

                    state <= IDLE;
                end

                default: begin
                    busy  <= 1'b0;
                    done  <= 1'b0;
                    state <= IDLE;
                end
            endcase
        end
    end
endmodule
