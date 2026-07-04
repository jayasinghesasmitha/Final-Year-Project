# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/env/conda/envs/cfu-common/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(Vcfu_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vcfu_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vcfu_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vcfu_COVERAGE 0)
# Timing mode?  0/1
set(Vcfu_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(Vcfu_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vcfu_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(Vcfu_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vcfu_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp" )
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vcfu_CLASSES_SLOW "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu__ConstPool_0.cpp" "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu___024root__Slow.cpp" "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu___024root__DepSet_h0cdad931__0__Slow.cpp" "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu___024root__DepSet_h1d3cd730__0__Slow.cpp" )
# Generated module classes, fast-path, compile with highest optimization
set(Vcfu_CLASSES_FAST "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu.cpp" "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu___024root__DepSet_h0cdad931__0.cpp" "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu___024root__DepSet_h1d3cd730__0.cpp" )
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vcfu_SUPPORT_SLOW "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/build/renode/CMakeFiles/libVtop.dir/Vcfu.dir/Vcfu__Syms.cpp" )
# Generated support classes, fast-path, compile with highest optimization
set(Vcfu_SUPPORT_FAST )
# All dependencies
set(Vcfu_DEPS "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/env/conda/envs/cfu-common/bin/verilator_bin" "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/env/conda/envs/cfu-common/share/verilator/include/verilated_std.sv" "/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/cfu.v" )
# User .cpp files (from .cpp's on Verilator command line)
set(Vcfu_USER_CLASSES )
