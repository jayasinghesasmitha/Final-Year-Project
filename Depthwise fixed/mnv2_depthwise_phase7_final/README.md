# mnv2_depthwise_phase7_final

Corrected Phase 7 standalone CFU test.

The important fix is the output read port in `rtl/mnv2_depthwise_top.v`:
`out_rd_data` is driven combinationally from `output_mem[out_rd_addr]`.
The CFU then returns that value through its one-cycle READ_OUTPUT response.

Run:

```bash
cd sim
make clean
make
```

Expected:

```text
PHASE7 PASS
CFU load/start/status/read path verified.
All 256 outputs equal 192.
```
