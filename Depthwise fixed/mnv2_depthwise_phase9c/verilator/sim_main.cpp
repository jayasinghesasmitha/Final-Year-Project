#include "Vmnv2_depthwise_cfu.h"

#include "cfu.h"
#include "renode_cfu.h"

static Vmnv2_depthwise_cfu *model = nullptr;

static void evaluate_model()
{
    if(model)
        model->eval();
}

class Mnv2Cfu : public Cfu
{
public:
    explicit Mnv2Cfu(Vmnv2_depthwise_cfu *m)
    {
        req_valid   = &m->cmd_valid;
        req_ready   = &m->cmd_ready;
        req_func_id = &m->cmd_payload_function_id;

        req_data0 = &m->cmd_payload_inputs_0;
        req_data1 = &m->cmd_payload_inputs_1;

        resp_valid = &m->rsp_valid;
        resp_ready = &m->rsp_ready;
        resp_data  = &m->rsp_payload_outputs_0;

        clk = &m->clk;
        rst = &m->reset;

        evaluateModel = evaluate_model;
    }
};

RenodeAgent *Init(void)
{
    static Vmnv2_depthwise_cfu dut;
    static Mnv2Cfu cfu(&dut);
    static RenodeAgent agent(&cfu);

    model = &dut;

    return &agent;
}