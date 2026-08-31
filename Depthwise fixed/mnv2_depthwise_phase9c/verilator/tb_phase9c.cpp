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

    printf("[TB] execute fn=%u data0=%08x data1=%08x\n",
           function_id, data0, data1);

    if (!dut->cmd_ready) {
        for (int i = 0; i < 100; ++i) {
            tick();

            if (dut->cmd_ready)
                break;
        }
    }

    if (!dut->cmd_ready) {
        printf("[TB] ERROR: cmd_ready timeout\n");
        dut->cmd_valid = 0;
        return 0;
    }

    for (int i = 0; i < 1000; ++i) {
        tick();

        if (dut->rsp_valid) {
            uint32_t result = dut->rsp_payload_outputs_0;

            printf("[TB] response=%08x after %d cycles\n",
                   result, i + 1);

            dut->cmd_valid = 0;
            eval();

            tick();

            return result;
        }
    }

    printf("[TB] ERROR: rsp_valid timeout\n");

    dut->cmd_valid = 0;
    eval();

    return 0;
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);

    dut = new Vmnv2_depthwise_cfu;

    dut->clk = 0;
    dut->reset = 1;

    dut->cmd_valid = 0;
    dut->cmd_payload_function_id = 0;
    dut->cmd_payload_inputs_0 = 0;
    dut->cmd_payload_inputs_1 = 0;
    dut->rsp_ready = 1;

    eval();

    printf("===== Phase 9C native HDL test =====\n");

    tick();
    dut->reset = 0;
    tick();

    printf("\n===== Testing command interface =====\n");

    /*
     * Test the seven function IDs used by the software.
     *
     * 0 = LOAD_IFMAP
     * 1 = LOAD_EXP_W
     * 2 = LOAD_DW_W
     * 3 = LOAD_PROJ_W
     * 4 = START
     * 5 = STATUS
     * 6 = READ_OUTPUT
     */

    execute(0, 0, 1);
    execute(1, 0, 1);
    execute(2, 0, 1);
    execute(3, 0, 1);

    uint32_t start = execute(4, 0, 0);
    printf("[TB] START returned %08x\n", start);

    uint32_t status = execute(5, 0, 0);
    printf("[TB] STATUS returned %08x\n", status);

    uint32_t output = execute(6, 0, 0);
    printf("[TB] OUTPUT returned %08x\n", output);

    printf("\n===== Phase 9C test complete =====\n");

    delete dut;

    return 0;
}