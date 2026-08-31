#include "Vmnv2_depthwise_cfu.h"
#include "verilated.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>

static constexpr int H    = 4;
static constexpr int W    = 4;
static constexpr int CIN  = 8;
static constexpr int CEXP = 24;
static constexpr int COUT = 16;

static constexpr int IFMAP_N = H * W * CIN;
static constexpr int EXP_W_N = CEXP * CIN;
static constexpr int DW_W_N  = CEXP * 9;
static constexpr int PROJ_W_N = COUT * CEXP;
static constexpr int OUT_N   = H * W * COUT;

static vluint64_t sim_time = 0;

double sc_time_stamp()
{
    return static_cast<double>(sim_time);
}


class Testbench {
public:

    Vmnv2_depthwise_cfu *dut;

    Testbench()
    {
        dut = new Vmnv2_depthwise_cfu;
    }

    ~Testbench()
    {
        delete dut;
    }

    void tick()
    {
        dut->clk = 0;
        dut->eval();
        sim_time++;

        dut->clk = 1;
        dut->eval();
        sim_time++;

        dut->clk = 0;
        dut->eval();
    }

    void reset()
    {
        dut->reset = 1;
        dut->cmd_valid = 0;
        dut->rsp_ready = 1;
        dut->cmd_payload_function_id = 0;
        dut->cmd_payload_inputs_0 = 0;
        dut->cmd_payload_inputs_1 = 0;

        for (int i = 0; i < 5; i++)
            tick();

        dut->reset = 0;

        tick();

        printf("[TB] Reset complete\n");
    }


    uint32_t command(
        uint32_t function_id,
        uint32_t input0,
        uint32_t input1
    )
    {
        /*
         * Wait until the CFU is ready.
         */
        while (!dut->cmd_ready)
            tick();

        dut->cmd_payload_function_id = function_id;
        dut->cmd_payload_inputs_0 = input0;
        dut->cmd_payload_inputs_1 = input1;
        dut->cmd_valid = 1;

        tick();

        dut->cmd_valid = 0;

        /*
         * Wait for response.
         */
        while (!dut->rsp_valid)
            tick();

        uint32_t result = dut->rsp_payload_outputs_0;

        tick();

        return result;
    }


    void load_ifmap(uint32_t addr, int8_t value)
    {
        command(
            0,
            addr,
            static_cast<uint32_t>(
                static_cast<int32_t>(value)
            )
        );
    }


    void load_expansion_weight(uint32_t addr, int8_t value)
    {
        command(
            1,
            addr,
            static_cast<uint32_t>(
                static_cast<int32_t>(value)
            )
        );
    }


    void load_depthwise_weight(uint32_t addr, int8_t value)
    {
        command(
            2,
            addr,
            static_cast<uint32_t>(
                static_cast<int32_t>(value)
            )
        );
    }


    void load_projection_weight(uint32_t addr, int8_t value)
    {
        command(
            3,
            addr,
            static_cast<uint32_t>(
                static_cast<int32_t>(value)
            )
        );
    }


    void start()
    {
        command(4, 0, 0);
    }


    uint32_t status()
    {
        return command(5, 0, 0);
    }


    int32_t read_output(uint32_t addr)
    {
        return static_cast<int32_t>(
            command(6, addr, 0)
        );
    }


    void run()
    {
        reset();

        printf("[TB] Loading IFMAP...\n");

        for (int i = 0; i < IFMAP_N; i++)
            load_ifmap(i, 1);


        printf("[TB] Loading expansion weights...\n");

        for (int i = 0; i < EXP_W_N; i++)
            load_expansion_weight(i, 1);


        printf("[TB] Loading depthwise weights...\n");

        for (int i = 0; i < DW_W_N; i++) {

            int value =
                ((i % 9) == 4) ? 1 : 0;

            load_depthwise_weight(i, value);
        }


        printf("[TB] Loading projection weights...\n");

        for (int i = 0; i < PROJ_W_N; i++)
            load_projection_weight(i, 1);


        printf("[TB] All data loaded\n");

        printf("[TB] Starting accelerator...\n");

        start();


        printf("[TB] Waiting for accelerator...\n");

        uint64_t cycles = 0;

        while (status() & 1u) {

            /*
             * STATUS itself is a CFU command.
             * The command helper advances the simulation.
             */
            cycles++;

            if (cycles > 20000) {

                printf(
                    "PHASE9 FAIL: accelerator timeout\n"
                );

                std::exit(1);
            }
        }


        printf(
            "[TB] Accelerator completed after %llu status checks\n",
            static_cast<unsigned long long>(cycles)
        );


        printf("[TB] Reading outputs...\n");


        for (int i = 0; i < OUT_N; i++) {

            int32_t value = read_output(i);

            if (value != 192) {

                printf(
                    "PHASE9 FAIL: output[%d] "
                    "expected=192 actual=%d\n",
                    i,
                    value
                );

                std::exit(1);
            }
        }


        printf("============================================\n");
        printf("PHASE9 PASS\n");
        printf("Verilator RTL CFU test passed.\n");
        printf("All 256 outputs equal 192.\n");
        printf("============================================\n");
    }
};


int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);

    Testbench tb;

    tb.run();

    return 0;
}