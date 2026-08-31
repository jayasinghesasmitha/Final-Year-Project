
# Phase 5 CFU interface

`mnv2_depthwise_cfu.v` wraps the Phase 4C fixed accelerator.

Command/data convention used by the testbench:

- CONFIG: no payload required
- LOAD_IFMAP: data[14:8] = address, data[7:0] = signed INT8 value
- LOAD_EXP_W: data[15:8] = address, data[7:0] = signed INT8 value
- LOAD_DW_W: data[15:8] = address, data[7:0] = signed INT8 value
- LOAD_PROJ_W: data[16:8] = address, data[7:0] = signed INT8 value
- START: no payload
- STATUS: returns `{done,busy}`
- READ_OUTPUT: data[7:0] = output address

This is a standalone CFU protocol prototype. Phase 6 will map this protocol to the actual
CFU-Playground/RISC-V instruction path and firmware without modifying the CFU-Playground repo.
