# This file is loaded by Renode's RISC-V custom instruction handler.
# It shares helper definitions with the main model via exec().
exec(open(r"/mnt/data/mnv2_depthwise_phase8c/renode/mnv2_depthwise_cfu.py").read())
handle(cpu, machine, instruction, 5)
