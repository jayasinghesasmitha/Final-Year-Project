//
// Copyright (c) 2025 Antmicro
//

#include "cfu.h"

#include <cstdio>
#include <stdexcept>


void Cfu::tick(bool countEnable, uint64_t steps)
{
    for(uint64_t i = 0; i < steps; i++)
    {
        *clk = 1;
        evaluateModel();

        *clk = 0;
        evaluateModel();
    }

    if(countEnable)
    {
        tickCounter += steps;
    }
}


void Cfu::timeoutTick(
    uint8_t* signal,
    uint8_t expectedValue,
    int timeout)
{
    while((*signal != expectedValue) && timeout > 0)
    {
        tick(true);
        timeout--;
    }

    if(*signal != expectedValue)
    {
        throw std::runtime_error("Operation timeout");
    }
}


uint64_t Cfu::execute(
    uint32_t functionID,
    uint32_t data0,
    uint32_t data1,
    int* error)
{
    uint64_t result = 0;

    fprintf(
        stderr,
        "[CFU] execute fn=%u data0=%08x data1=%08x\n",
        functionID,
        data0,
        data1
    );
    fflush(stderr);


    /*
     * Renode passes the CFU function ID using the wider
     * custom-instruction representation.
     *
     * The RTL expects a 3-bit function ID:
     *
     *   0 = LOAD_IFMAP
     *   1 = LOAD_EXP_W
     *   2 = LOAD_DW_W
     *   3 = LOAD_PROJ_W
     *   4 = START
     *   5 = STATUS
     *   6 = READ_OUTPUT
     *
     * The Renode-side ID is encoded with the function
     * number in bits [5:3].
     */
    uint32_t hdlFunctionID = (functionID >> 3) & 0x7;


    *req_func_id = static_cast<uint8_t>(hdlFunctionID);
    *req_data0 = data0;
    *req_data1 = data1;

    *req_valid = 1;
    *resp_ready = 1;

    *error = 0;


    /*
     * Present the request to the Verilated model.
     */
    evaluateModel();


    /*
     * The request should normally be accepted immediately.
     * If not, advance the model until req_ready becomes true.
     */
    if(*req_ready != 1)
    {
        timeoutTick(
            req_ready,
            1,
            DEFAULT_TIMEOUT
        );
    }


    /*
     * Wait for the response.
     *
     * The RTL produces a response one or more clock cycles
     * after accepting the request.
     */
    if(*resp_valid)
    {
        result = *resp_data;

        fprintf(
            stderr,
            "[CFU] immediate response=%08x\n",
            static_cast<uint32_t>(result)
        );
        fflush(stderr);
    }
    else
    {
        timeoutTick(
            resp_valid,
            1,
            DEFAULT_TIMEOUT
        );

        result = *resp_data;

        fprintf(
            stderr,
            "[CFU] delayed response=%08x\n",
            static_cast<uint32_t>(result)
        );
        fflush(stderr);
    }


    /*
     * Complete the response handshake.
     *
     * rsp_valid in the RTL is cleared on the next clock
     * when rsp_ready is asserted.
     */
    tick(true);


    /*
     * Release the request.
     */
    *req_valid = 0;

    evaluateModel();


    /*
     * START launches the multi-cycle accelerator.
     *
     * Native simulation shows that the complete accelerator
     * execution requires approximately 2000 cycles.
     *
     * Give the model enough simulation time after START so
     * that the accelerator can progress before Renode issues
     * the next instruction.
     */
    if(hdlFunctionID == 4)
    {
        tick(true, 2000);
    }
    else
    {
        /*
         * Small settling interval for normal transactions.
         */
        tick(true, 4);
    }


    /*
     * Make sure a stale response does not remain asserted.
     */
    if(*resp_valid)
    {
        tick(true);
    }


    return result;
}


void Cfu::reset()
{
    *rst = 1;

    tick(true);

    *rst = 0;

    tick(true);
}