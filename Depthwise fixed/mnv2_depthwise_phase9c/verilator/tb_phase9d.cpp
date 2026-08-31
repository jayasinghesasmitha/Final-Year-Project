#include "Vmnv2_depthwise_cfu.h"
#include "verilated.h"

#include <cstdint>
#include <cstdio>

static Vmnv2_depthwise_cfu *dut;

static void eval()
{
    dut->eval();
}

static void tick()
{
    dut->clk = 1;
    eval();

    dut->clk = 0;
    eval();
}

/*
 * Execute one CFU command.
 *
 * The command is asserted only until the response is received.
 * This prevents the same command from being accidentally accepted
 * repeatedly.
 */
static uint32_t execute(uint32_t function_id,
                        uint32_t data0,
                        uint32_t data1)
{
    dut->cmd_payload_function_id = function_id;
    dut->cmd_payload_inputs_0 = data0;
    dut->cmd_payload_inputs_1 = data1;

    dut->cmd_valid = 1;
    dut->rsp_ready = 1;

    eval();

    /*
     * Wait until the CFU accepts the command.
     */
    if (!dut->cmd_ready) {
        for (int i = 0; i < 100; ++i) {
            tick();

            if (dut->cmd_ready)
                break;
        }
    }

    if (!dut->cmd_ready) {
        printf("[TB] ERROR: cmd_ready timeout fn=%u\n",
               function_id);

        dut->cmd_valid = 0;
        eval();

        return 0;
    }

    /*
     * Wait for the response.
     */
    for (int i = 0; i < 1000; ++i) {

        tick();

        if (dut->rsp_valid) {

            uint32_t result =
                dut->rsp_payload_outputs_0;

            printf("[TB] fn=%u data0=%08x data1=%08x -> %08x (%d cycles)\n",
                   function_id,
                   data0,
                   data1,
                   result,
                   i + 1);

            /*
             * Deassert command immediately after the
             * transaction completes.
             */
            dut->cmd_valid = 0;
            eval();

            /*
             * Give the CFU one clean cycle to finish
             * the handshake.
             */
            tick();

            return result;
        }
    }

    printf("[TB] ERROR: rsp_valid timeout fn=%u\n",
           function_id);

    dut->cmd_valid = 0;
    eval();

    return 0;
}


/*
 * Load deterministic test data.
 */
static void load_test_data()
{
    printf("\n===== Loading test data =====\n");

    /*
     * IFMAP
     *
     * H = 4
     * W = 4
     * CIN = 8
     *
     * Total = 128 values
     */
    printf("[TB] Loading IFMAP...\n");

    for (uint32_t i = 0; i < 4 * 4 * 8; ++i) {
        execute(0, i, 1);
    }


    /*
     * Expansion weights
     *
     * CEXP = 24
     * CIN  = 8
     *
     * Total = 192 values
     */
    printf("[TB] Loading expansion weights...\n");

    for (uint32_t i = 0; i < 24 * 8; ++i) {
        execute(1, i, 1);
    }


    /*
     * Depthwise weights
     *
     * CEXP = 24
     * Kernel = 3x3
     *
     * Total = 216 values
     */
    printf("[TB] Loading depthwise weights...\n");

    for (uint32_t i = 0; i < 24 * 9; ++i) {
        execute(2, i, 1);
    }


    /*
     * Projection weights
     *
     * COUT = 16
     * CEXP = 24
     *
     * Total = 384 values
     */
    printf("[TB] Loading projection weights...\n");

    for (uint32_t i = 0; i < 16 * 24; ++i) {
        execute(3, i, 1);
    }

    printf("[TB] Test data loaded.\n");
}


/*
 * Read STATUS once.
 *
 * STATUS format:
 *
 * bit 0 = busy
 * bit 1 = done
 */
static uint32_t read_status()
{
    return execute(5, 0, 0);
}


int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);

    dut = new Vmnv2_depthwise_cfu;

    /*
     * Initial signal values.
     */
    dut->clk = 0;
    dut->reset = 1;

    dut->cmd_valid = 0;

    dut->cmd_payload_function_id = 0;
    dut->cmd_payload_inputs_0 = 0;
    dut->cmd_payload_inputs_1 = 0;

    dut->rsp_ready = 1;

    eval();

    printf("===== Phase 9D native functional test =====\n");


    /*
     * ============================================================
     * RESET
     * ============================================================
     */

    printf("\n===== Reset =====\n");

    tick();

    dut->reset = 0;

    tick();


    /*
     * ============================================================
     * LOAD DATA
     * ============================================================
     */

    load_test_data();


    /*
     * ============================================================
     * START
     * ============================================================
     */

    printf("\n===== Starting accelerator =====\n");

    uint32_t start_result =
        execute(4, 0, 0);

    printf("[TB] START returned %08x\n",
           start_result);


    /*
     * ============================================================
     * ACCELERATOR EXECUTION
     * ============================================================
     *
     * Do NOT continuously issue STATUS commands.
     *
     * Instead, allow the accelerator to receive uninterrupted
     * clock cycles.
     *
     * The workload is approximately:
     *
     * Expansion:
     *   16 spatial positions
     *   x 24 expansion channels
     *   x 8 input channels
     *
     * Depthwise:
     *   16 spatial positions
     *   x 24 channels
     *   x 9 taps
     *
     * Projection:
     *   16 spatial positions
     *   x 16 output channels
     *   x 24 channels
     *
     * Therefore tens of thousands of cycles are expected.
     */

    printf("\n===== Running accelerator =====\n");

    bool finished = false;

    const int MAX_CYCLES = 100000;

    for (int cycle = 0;
         cycle < MAX_CYCLES;
         ++cycle) {

        tick();

        /*
         * Check STATUS only occasionally.
         *
         * This keeps the accelerator running normally
         * instead of injecting a STATUS transaction every
         * single clock cycle.
         */
        if ((cycle % 1000) == 0) {

            uint32_t status =
                read_status();

            bool busy =
                (status & 1u) != 0;

            bool done =
                (status & 2u) != 0;

            printf("[TB] cycle=%d status=%08x busy=%d done=%d\n",
                   cycle,
                   status,
                   busy,
                   done);

            if (!busy && done) {

                printf("[TB] DONE after approximately %d cycles\n",
                       cycle);

                finished = true;

                break;
            }
        }
    }


    /*
     * ============================================================
     * FINAL STATUS CHECK
     * ============================================================
     */

    if (!finished) {

        uint32_t status =
            read_status();

        printf("[TB] FINAL STATUS = %08x\n",
               status);

        printf("[TB] ERROR: accelerator did not finish\n");

        delete dut;

        return 1;
    }


    /*
     * ============================================================
     * READ OUTPUT
     * ============================================================
     */

    printf("\n===== Reading output =====\n");

    uint32_t output =
        execute(6, 0, 0);

    printf("[TB] OUTPUT[0] = %08x (%d)\n",
           output,
           static_cast<int32_t>(output));


    /*
     * ============================================================
     * COMPLETE
     * ============================================================
     */

    printf("\n===== Phase 9D test complete =====\n");

    delete dut;

    return 0;
}