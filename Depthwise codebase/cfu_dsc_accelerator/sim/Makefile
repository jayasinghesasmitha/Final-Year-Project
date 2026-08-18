/*******************************************************************************
 * CFU DSC Accelerator - Makefile
 *
 * Build system for simulation and synthesis
 ******************************************************************************/

# Directories
RTL_DIR = ../rtl
CFU_DIR = ../cfu
SIM_DIR = .
SOFT_DIR = ../software

# Tools
IVERILOG = iverilog
VVP = vvp
GTKWAVE = gtkwave

# Source files
RTL_SRCS = $(RTL_DIR)/cfu_dsc_defines.v \
           $(RTL_DIR)/expansion_engine.v \
           $(RTL_DIR)/expansion_unit.v \
           $(RTL_DIR)/depthwise_unit.v \
           $(RTL_DIR)/projection_engine.v \
           $(RTL_DIR)/projection_unit.v \
           $(RTL_DIR)/post_processing_unit.v \
           $(RTL_DIR)/ifmap_buffer.v \
           $(RTL_DIR)/expansion_filter_buffer.v \
           $(RTL_DIR)/depthwise_filter_buffer.v \
           $(RTL_DIR)/instruction_controller.v

CFU_SRCS = $(CFU_DIR)/cfu_dsc_interface.v \
           $(CFU_DIR)/cfu_dsc_accelerator.v

TEST_SRCS = $(SIM_DIR)/tb_cfu_dsc_accelerator.v

# Targets
TARGET = cfu_dsc_sim
VCD_FILE = cfu_dsc_accelerator.vcd

# Default target
.PHONY: all sim wave clean

all: sim

# Compile and simulate
sim: $(TARGET)
	$(VVP) $(TARGET)

# Compile only
$(TARGET): $(RTL_SRCS) $(CFU_SRCS) $(TEST_SRCS)
	$(IVERILOG) -g2012 -Wall -o $(TARGET) \
		-I$(RTL_DIR) \
		$(RTL_SRCS) \
		$(CFU_SRCS) \
		$(TEST_SRCS)

# View waveforms
wave: $(VCD_FILE)
	$(GTKWAVE) $(VCD_FILE) &

# Clean build artifacts
clean:
	rm -f $(TARGET) $(VCD_FILE)
	rm -f *.vcd

# Test individual modules
.PHONY: test_expansion test_depthwise test_projection

test_expansion:
	$(IVERILOG) -g2012 -Wall -o test_exp \
		-I$(RTL_DIR) \
		$(RTL_DIR)/cfu_dsc_defines.v \
		$(RTL_DIR)/expansion_engine.v \
		$(RTL_DIR)/post_processing_unit.v \
		$(RTL_DIR)/expansion_unit.v \
		tb_expansion_unit.v
	$(VVP) test_exp

test_depthwise:
	$(IVERILOG) -g2012 -Wall -o test_dw \
		-I$(RTL_DIR) \
		$(RTL_DIR)/cfu_dsc_defines.v \
		$(RTL_DIR)/post_processing_unit.v \
		$(RTL_DIR)/depthwise_unit.v \
		tb_depthwise_unit.v
	$(VVP) test_dw

test_projection:
	$(IVERILOG) -g2012 -Wall -o test_proj \
		-I$(RTL_DIR) \
		$(RTL_DIR)/cfu_dsc_defines.v \
		$(RTL_DIR)/projection_engine.v \
		$(RTL_DIR)/post_processing_unit.v \
		$(RTL_DIR)/projection_unit.v \
		tb_projection_unit.v
	$(VVP) test_proj

# Help
.PHONY: help
help:
	@echo "CFU DSC Accelerator Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  all          - Build and run simulation (default)"
	@echo "  sim          - Run simulation"
	@echo "  wave         - View waveforms with GTKWave"
	@echo "  clean        - Remove build artifacts"
	@echo "  test_expansion   - Test expansion unit only"
	@echo "  test_depthwise   - Test depthwise unit only"
	@echo "  test_projection  - Test projection unit only"
	@echo "  help         - Show this help"
