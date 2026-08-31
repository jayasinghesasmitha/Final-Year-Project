# Phase 8D CFU functional model
#
# Renode 1.16.x compatible RISC-V custom instruction handler.
#
# Available Renode variables:
#   cpu
#   machine
#   state
#   instruction


def _reg(index):
    return int(cpu.GetRegister(index).RawValue)


def _set_rd(value):
    rd = (instruction >> 7) & 0x1f

    if rd != 0:
        # IMPORTANT:
        # Renode expects a RegisterValue object here, not a Python int.
        cpu.SetRegister(
            rd,
            cpu.GetRegister(rd).Create(value & 0xffffffff, 32)
        )


def _ensure():
    if 'ifmap' not in state:
        state['ifmap'] = [0] * 128
        state['expw'] = [0] * 192
        state['dww'] = [0] * 216
        state['projw'] = [0] * 384
        state['out'] = [0] * 256
        state['busy'] = 0
        state['done'] = 0


def _compute():

    _ensure()

    H = 4
    W = 4
    CIN = 8
    CEXP = 24
    COUT = 16

    ifmap = state['ifmap']
    expw = state['expw']
    dww = state['dww']
    projw = state['projw']

    expanded = [0] * (H * W * CEXP)
    dw = [0] * (H * W * CEXP)
    out = [0] * (H * W * COUT)

    # ============================================================
    # Expansion
    # ============================================================

    for s in range(H * W):

        for ec in range(CEXP):

            acc = 0

            for ci in range(CIN):

                acc += (
                    ifmap[s * CIN + ci] *
                    expw[ec * CIN + ci]
                )

            expanded[s * CEXP + ec] = acc

    # ============================================================
    # Depthwise 3x3
    # ============================================================

    for r in range(H):

        for c in range(W):

            s = r * W + c

            for ch in range(CEXP):

                acc = 0

                for tap in range(9):

                    rr = r + (tap // 3) - 1
                    cc = c + (tap % 3) - 1

                    if (
                        rr >= 0 and
                        rr < H and
                        cc >= 0 and
                        cc < W
                    ):

                        acc += (
                            expanded[(rr * W + cc) * CEXP + ch] *
                            dww[ch * 9 + tap]
                        )

                dw[s * CEXP + ch] = acc

    # ============================================================
    # Projection
    # ============================================================

    for s in range(H * W):

        for oc in range(COUT):

            acc = 0

            for ch in range(CEXP):

                acc += (
                    dw[s * CEXP + ch] *
                    projw[oc * CEXP + ch]
                )

            out[s * COUT + oc] = acc

    state['out'] = out

    state['busy'] = 0
    state['done'] = 1


# ================================================================
# Main custom-instruction handler
# ================================================================

_ensure()

rs1 = (instruction >> 15) & 0x1f
rs2 = (instruction >> 20) & 0x1f

a = _reg(rs1)
b = _reg(rs2)

# CFU function ID
fn = (instruction >> 25) & 0x7f


# ================================================================
# 0: LOAD IFMAP
# ================================================================

if fn == 0:

    if a < len(state['ifmap']):

        value = b & 0xff

        if value & 0x80:
            value -= 256

        state['ifmap'][a] = value

    _set_rd(0)


# ================================================================
# 1: LOAD EXPANSION WEIGHT
# ================================================================

elif fn == 1:

    if a < len(state['expw']):

        value = b & 0xff

        if value & 0x80:
            value -= 256

        state['expw'][a] = value

    _set_rd(0)


# ================================================================
# 2: LOAD DEPTHWISE WEIGHT
# ================================================================

elif fn == 2:

    if a < len(state['dww']):

        value = b & 0xff

        if value & 0x80:
            value -= 256

        state['dww'][a] = value

    _set_rd(0)


# ================================================================
# 3: LOAD PROJECTION WEIGHT
# ================================================================

elif fn == 3:

    if a < len(state['projw']):

        value = b & 0xff

        if value & 0x80:
            value -= 256

        state['projw'][a] = value

    _set_rd(0)


# ================================================================
# 4: START
# ================================================================

elif fn == 4:

    state['busy'] = 1
    state['done'] = 0

    _compute()

    _set_rd(0)


# ================================================================
# 5: STATUS
#
# bit 0 = busy
# bit 1 = done
# ================================================================

elif fn == 5:

    status = (
        (state['done'] << 1) |
        state['busy']
    )

    _set_rd(status)


# ================================================================
# 6: READ OUTPUT
# ================================================================

elif fn == 6:

    if a < len(state['out']):
        value = state['out'][a]
    else:
        value = 0

    _set_rd(value)


# ================================================================
# Unknown function
# ================================================================

else:

    _set_rd(0)