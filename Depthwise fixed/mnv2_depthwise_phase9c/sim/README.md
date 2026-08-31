Phase 8D has two verification layers:

1. Renode/RISC-V custom-instruction execution:
   `cd ../sw && make`
   then from the project root:
   `renode renode/mnv2_depthwise.resc`

2. RTL regression:
   copy the already-verified `mnv2_depthwise_top.v`, `mnv2_depthwise_cfu.v`,
   and Phase 8B/8C testbench into this project's rtl/sim directories.
