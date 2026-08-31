Phase 4 keeps the CPU-facing CFU protocol separate from the datapath.

Phase 5 will connect the protocol commands to the explicit memory write ports,
START/BUSY/DONE signals and output read port of `mnv2_depthwise_top`.
