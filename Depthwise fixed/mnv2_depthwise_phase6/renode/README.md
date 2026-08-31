# Phase 6 Renode integration

Phase 6 defines the CFU instruction contract, but a complete Renode run requires
a RISC-V SoC model exposing the same CFU custom-instruction path as the
CFU-Playground target.

The standalone Verilog CFU interface is:

- `cmd_valid`
- `cmd_ready`
- `cmd_payload_function_id[2:0]`
- `cmd_payload_inputs_0[31:0]`
- `cmd_payload_inputs_1[31:0]`
- `rsp_valid`
- `rsp_ready`
- `rsp_payload_outputs_0[31:0]`

Function IDs are:

0. IFMAP load
1. Expansion weight load
2. Depthwise weight load
3. Projection weight load
4. Start
5. Status
6. Output read

The next integration step is to connect this wrapper to the exact RISC-V/SoC
CFU bridge used by the already-tested CFU-Playground setup. No files in
CFU-Playground are required to be modified by this standalone project.
