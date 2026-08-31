# Phase 8C functional Renode model for the MNv2 CFU custom-0 instructions.
#
# This is a software model of the accelerator behavior for Renode.
# The Verilog RTL remains the hardware implementation and is verified
# independently in sim/.
#
# R-format:
# funct7 | rs2 | rs1 | funct3 | rd | opcode
#   7       5     5      3       5     7
#
# opcode = custom-0 = 0x0B
# funct3 = 0
# funct7 = function ID (0..6)

H = 4
W = 4
CIN = 8
CEXP = 24
COUT = 16

IFMAP_N = H * W * CIN
EXP_W_N = CEXP * CIN
DW_W_N = CEXP * 9
PROJ_W_N = COUT * CEXP
OUT_N = H * W * COUT

def _bits(v, lo, width):
    return (int(v) >> lo) & ((1 << width) - 1)

def _read_reg(cpu, idx):
    if idx == 0:
        return 0
    return int(cpu.GetRegisterUnsafe(idx).RawValue)

def _write_reg(cpu, idx, value):
    if idx != 0:
        cpu.SetRegisterUnsafe(idx, int(value) & 0xffffffff)

def _state(machine):
    # A single persistent dictionary is kept in the CPU state object.
    # The first handler call creates it.
    cpu = machine['sysbus.cpu']
    try:
        st = cpu.GetState('mnv2_depthwise')
        if st is None:
            st = {}
            cpu.SetState('mnv2_depthwise', st)
        return st
    except:
        # Fallback: module-global state for Renode versions where the
        # generic CPU state API is not exposed to Python.
        global fallback_state
        try:
            return fallback_state
        except:
            fallback_state = {}
            return fallback_state

def _ensure(st):
    if 'ifmap' not in st:
        st['ifmap'] = [0] * IFMAP_N
        st['exp_w'] = [0] * EXP_W_N
        st['dw_w'] = [0] * DW_W_N
        st['proj_w'] = [0] * PROJ_W_N
        st['output'] = [0] * OUT_N
        st['busy'] = 0
        st['done'] = 0

def _s8(x):
    x = int(x) & 0xff
    return x - 256 if x & 0x80 else x

def _run(st):
    # Functional model of:
    # Expansion -> 3x3 depthwise -> Projection.
    expanded = [0] * (H * W * CEXP)
    dwout = [0] * (H * W * CEXP)

    for s in range(H * W):
        for e in range(CEXP):
            acc = 0
            for ci in range(CIN):
                acc += _s8(st['ifmap'][s*CIN + ci]) * _s8(st['exp_w'][e*CIN + ci])
            expanded[s*CEXP + e] = acc

    for r in range(H):
        for c in range(W):
            s = r*W+c
            for ch in range(CEXP):
                acc = 0
                for tap in range(9):
                    rr = r + (tap // 3) - 1
                    cc = c + (tap % 3) - 1
                    if 0 <= rr < H and 0 <= cc < W:
                        acc += expanded[(rr*W+cc)*CEXP+ch] * _s8(st['dw_w'][ch*9+tap])
                dwout[s*CEXP+ch] = acc

    for s in range(H*W):
        for oc in range(COUT):
            acc = 0
            for ch in range(CEXP):
                acc += dwout[s*CEXP+ch] * _s8(st['proj_w'][oc*CEXP+ch])
            st['output'][s*COUT+oc] = acc & 0xffffffff

def handle(cpu, machine, instruction, expected_fn):
    st = _state(machine)
    _ensure(st)

    funct7 = _bits(instruction, 25, 7)
    rs2 = _bits(instruction, 20, 5)
    rs1 = _bits(instruction, 15, 5)
    rd = _bits(instruction, 7, 5)

    a = _read_reg(cpu, rs1)
    b = _read_reg(cpu, rs2)
    result = 0

    if funct7 == 0:
        addr = a & 0x7f
        if addr < IFMAP_N:
            st['ifmap'][addr] = _s8(b)
    elif funct7 == 1:
        addr = a & 0xff
        if addr < EXP_W_N:
            st['exp_w'][addr] = _s8(b)
    elif funct7 == 2:
        addr = a & 0xff
        if addr < DW_W_N:
            st['dw_w'][addr] = _s8(b)
    elif funct7 == 3:
        addr = a & 0x1ff
        if addr < PROJ_W_N:
            st['proj_w'][addr] = _s8(b)
    elif funct7 == 4:
        if not st['busy']:
            st['busy'] = 1
            st['done'] = 0
            _run(st)
            st['busy'] = 0
            st['done'] = 1
    elif funct7 == 5:
        result = (st['done'] << 1) | st['busy']
    elif funct7 == 6:
        addr = a & 0xff
        if addr < OUT_N:
            result = st['output'][addr]
    else:
        result = 0

    _write_reg(cpu, rd, result)

    try:
        cpu.DebugLog("MNv2 CFU funct7={} rs1={} rs2={} rd={} result=0x{:08x}".format(
            funct7, rs1, rs2, rd, result & 0xffffffff))
    except:
        pass
