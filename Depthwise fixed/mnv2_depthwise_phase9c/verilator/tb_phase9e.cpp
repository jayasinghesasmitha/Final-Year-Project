#include "Vmnv2_depthwise_cfu.h"
#include "verilated.h"

#include <cstdint>
#include <cstdio>

static Vmnv2_depthwise_cfu *dut;


/*
 * ============================================================
 * SIMULATION HELPERS
 * ============================================================
 */

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
 * ============================================================
 * CFU COMMAND
 * ============================================================
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
     * Wait until command can be accepted.
     */

    if (!dut->cmd_ready) {

        for (int i = 0; i < 100; ++i) {

            tick();

            if (dut->cmd_ready)
                break;
        }
    }


    if (!dut->cmd_ready) {

        printf(
            "[TB] ERROR: cmd_ready timeout fn=%u\n",
            function_id
        );

        dut->cmd_valid = 0;
        eval();

        return 0;
    }


    /*
     * Wait for response.
     */

    for (int i = 0; i < 1000; ++i) {

        tick();

        if (dut->rsp_valid) {

            uint32_t result =
                dut->rsp_payload_outputs_0;


            /*
             * End this transaction.
             */

            dut->cmd_valid = 0;
            eval();

            tick();

            return result;
        }
    }


    printf(
        "[TB] ERROR: rsp_valid timeout fn=%u\n",
        function_id
    );


    dut->cmd_valid = 0;
    eval();

    return 0;
}


/*
 * ============================================================
 * TEST PARAMETERS
 * ============================================================
 */

static const int H    = 4;
static const int W    = 4;

static const int CIN  = 8;
static const int CEXP = 24;
static const int COUT = 16;

static const int SPATIAL_COUNT = H * W;


/*
 * ============================================================
 * SOFTWARE GOLDEN MODEL
 * ============================================================
 *
 * Test data:
 *
 *   IFMAP              = 1
 *   Expansion weights  = 1
 *   Depthwise weights  = 1
 *   Projection weights = 1
 *
 *
 * Expansion:
 *
 *   8 input channels
 *
 *   1 * 1 + 1 * 1 + ... + 1 * 1
 *   = 8
 *
 *
 * Depthwise:
 *
 *   Each valid neighbour contributes 8.
 *
 *
 * Projection:
 *
 *   24 expansion channels.
 *
 *
 * Therefore:
 *
 *   output =
 *
 *       8
 *       × valid_neighbors
 *       × 24
 *
 *   output =
 *
 *       192 × valid_neighbors
 *
 *
 * For a 4x4 image:
 *
 *   corner = 4 neighbours
 *   edge   = 6 neighbours
 *   center = 9 neighbours
 *
 * Therefore:
 *
 *   corner =  768
 *   edge   = 1152
 *   center = 1728
 *
 * ============================================================
 */

static uint32_t expected_output(uint32_t spatial_idx)
{
    const int row =
        spatial_idx / W;

    const int col =
        spatial_idx % W;


    int valid_neighbors = 0;


    /*
     * 3x3 depthwise window.
     */

    for (int kr = -1;
         kr <= 1;
         ++kr) {

        for (int kc = -1;
             kc <= 1;
             ++kc) {

            const int rr =
                row + kr;

            const int cc =
                col + kc;


            /*
             * Zero-padding:
             *
             * Only neighbours inside the
             * 4x4 image are valid.
             */

            if (rr >= 0 &&
                rr < H &&
                cc >= 0 &&
                cc < W) {

                valid_neighbors++;
            }
        }
    }


    return 192u *
           static_cast<uint32_t>(
               valid_neighbors
           );
}


/*
 * ============================================================
 * LOAD TEST DATA
 * ============================================================
 */

static void load_test_data()
{
    printf(
        "\n===== Loading test data =====\n"
    );


    /*
     * --------------------------------------------------------
     * IFMAP
     *
     * H x W x CIN
     *
     * 4 x 4 x 8 = 128 values
     *
     * Every value = 1
     * --------------------------------------------------------
     */

    printf(
        "[TB] Loading IFMAP...\n"
    );


    for (uint32_t i = 0;
         i < H * W * CIN;
         ++i) {

        execute(
            0,
            i,
            1
        );
    }


    /*
     * --------------------------------------------------------
     * EXPANSION WEIGHTS
     *
     * CEXP x CIN
     *
     * 24 x 8 = 192 values
     *
     * Every value = 1
     * --------------------------------------------------------
     */

    printf(
        "[TB] Loading expansion weights...\n"
    );


    for (uint32_t i = 0;
         i < CEXP * CIN;
         ++i) {

        execute(
            1,
            i,
            1
        );
    }


    /*
     * --------------------------------------------------------
     * DEPTHWISE WEIGHTS
     *
     * CEXP x 3 x 3
     *
     * 24 x 9 = 216 values
     *
     * Every value = 1
     * --------------------------------------------------------
     */

    printf(
        "[TB] Loading depthwise weights...\n"
    );


    for (uint32_t i = 0;
         i < CEXP * 9;
         ++i) {

        execute(
            2,
            i,
            1
        );
    }


    /*
     * --------------------------------------------------------
     * PROJECTION WEIGHTS
     *
     * COUT x CEXP
     *
     * 16 x 24 = 384 values
     *
     * Every value = 1
     * --------------------------------------------------------
     */

    printf(
        "[TB] Loading projection weights...\n"
    );


    for (uint32_t i = 0;
         i < COUT * CEXP;
         ++i) {

        execute(
            3,
            i,
            1
        );
    }


    printf(
        "[TB] Test data loaded.\n"
    );
}


/*
 * ============================================================
 * STATUS
 * ============================================================
 *
 * bit 0 = busy
 * bit 1 = done
 *
 * ============================================================
 */

static uint32_t read_status()
{
    return execute(
        5,
        0,
        0
    );
}


/*
 * ============================================================
 * MAIN
 * ============================================================
 */

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);


    dut =
        new Vmnv2_depthwise_cfu;


    /*
     * --------------------------------------------------------
     * INITIAL SIGNALS
     * --------------------------------------------------------
     */

    dut->clk = 0;

    dut->reset = 1;

    dut->cmd_valid = 0;

    dut->cmd_payload_function_id = 0;

    dut->cmd_payload_inputs_0 = 0;

    dut->cmd_payload_inputs_1 = 0;

    dut->rsp_ready = 1;


    eval();


    printf(
        "===== Phase 9E native functional test =====\n"
    );


    /*
     * ========================================================
     * RESET
     * ========================================================
     */

    printf(
        "\n===== Reset =====\n"
    );


    tick();


    dut->reset = 0;


    tick();


    /*
     * ========================================================
     * LOAD DATA
     * ========================================================
     */

    load_test_data();


    /*
     * ========================================================
     * START ACCELERATOR
     * ========================================================
     */

    printf(
        "\n===== Starting accelerator =====\n"
    );


    uint32_t start_result =
        execute(
            4,
            0,
            0
        );


    printf(
        "[TB] START returned %08x\n",
        start_result
    );


    /*
     * ========================================================
     * RUN ACCELERATOR
     * ========================================================
     *
     * Do not continuously send STATUS commands.
     *
     * Allow the accelerator to run freely.
     *
     * Approximate workload:
     *
     * Expansion:
     *
     *   16 positions
     *   x 24 expansion channels
     *   x 8 input channels
     *
     * Depthwise:
     *
     *   16 positions
     *   x 24 channels
     *   x 9 taps
     *
     * Projection:
     *
     *   16 positions
     *   x 16 output channels
     *   x 24 channels
     *
     * ========================================================
     */

    printf(
        "\n===== Running accelerator =====\n"
    );


    bool finished = false;


    const int MAX_CYCLES = 100000;


    for (int cycle = 0;
         cycle < MAX_CYCLES;
         ++cycle) {

        tick();


        /*
         * Check status every 1000 cycles.
         */

        if ((cycle % 1000) == 0) {

            uint32_t status =
                read_status();


            bool busy =
                (status & 1u) != 0;


            bool done =
                (status & 2u) != 0;


            printf(
                "[TB] cycle=%d "
                "status=%08x "
                "busy=%d "
                "done=%d\n",

                cycle,
                status,
                busy,
                done
            );


            if (!busy && done) {

                printf(
                    "[TB] DONE after approximately "
                    "%d cycles\n",
                    cycle
                );


                finished = true;


                break;
            }
        }
    }


    /*
     * ========================================================
     * CHECK COMPLETION
     * ========================================================
     */

    if (!finished) {

        uint32_t status =
            read_status();


        printf(
            "[TB] FINAL STATUS = %08x\n",
            status
        );


        printf(
            "[TB] ERROR: accelerator did not finish\n"
        );


        delete dut;


        return 1;
    }


    /*
     * ========================================================
     * READ AND VERIFY ALL OUTPUTS
     * ========================================================
     */

    printf(
        "\n===== Reading and verifying all outputs =====\n"
    );


    int failures = 0;


    /*
     * There are:
     *
     *   16 spatial positions
     *   x 16 output channels
     *
     *   = 256 outputs
     */

    const uint32_t OUTPUT_COUNT =
        SPATIAL_COUNT * COUT;


    for (uint32_t spatial = 0;
         spatial < SPATIAL_COUNT;
         ++spatial) {


        uint32_t expected =
            expected_output(
                spatial
            );


        printf(
            "[TB] spatial=%u expected=%u\n",
            spatial,
            expected
        );


        for (uint32_t ch = 0;
             ch < COUT;
             ++ch) {


            uint32_t output_index =
                spatial * COUT + ch;


            /*
             * Function 6:
             *
             * Read output memory.
             */

            uint32_t output =
                execute(
                    6,
                    output_index,
                    0
                );


            int32_t signed_output =
                static_cast<int32_t>(
                    output
                );


            /*
             * Compare against golden model.
             */

            if (signed_output !=
                static_cast<int32_t>(
                    expected
                )) {


                printf(
                    "[TB] FAIL OUTPUT[%u] "
                    "spatial=%u "
                    "ch=%u "
                    "expected=%u "
                    "got=%d\n",

                    output_index,
                    spatial,
                    ch,
                    expected,
                    signed_output
                );


                failures++;
            }
        }
    }


    /*
     * ========================================================
     * FINAL RESULT
     * ========================================================
     */

    if (failures == 0) {

        printf(
            "\n[TB] PASS: all %u outputs "
            "match the software golden model\n",

            OUTPUT_COUNT
        );


        printf(
            "\n===== Phase 9E test complete =====\n"
        );


        delete dut;


        return 0;
    }


    /*
     * --------------------------------------------------------
     * FAILURE
     * --------------------------------------------------------
     */

    printf(
        "\n[TB] FAIL: %d / %u outputs incorrect\n",

        failures,
        OUTPUT_COUNT
    );


    delete dut;


    return 1;
}