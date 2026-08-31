cmake_minimum_required(VERSION 3.16)

project(mnv2_depthwise_cfu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
find_program(VERILATOR verilator REQUIRED)

set(RENODE_API
    ${CMAKE_CURRENT_SOURCE_DIR}/renode_api)

set(VERILATOR_BUILD
    ${CMAKE_BINARY_DIR}/verilated)

set(RTL_TOP
    ${CMAKE_CURRENT_SOURCE_DIR}/../rtl/mnv2_depthwise_cfu.v)

set(RTL_ACCEL
    ${CMAKE_CURRENT_SOURCE_DIR}/../rtl/mnv2_depthwise_top.v)


add_custom_target(verilate ALL

    COMMAND ${CMAKE_COMMAND} -E make_directory
            ${VERILATOR_BUILD}

    COMMAND ${VERILATOR}
            --cc
            --Mdir ${VERILATOR_BUILD}
            -CFLAGS "-fPIC"
            --top-module mnv2_depthwise_cfu
            -Wall
            -Wno-fatal
            -Wno-WIDTHEXPAND
            -Wno-UNUSEDSIGNAL
            -Wno-BLKSEQ
            -Wno-EOFNEWLINE
            ${RTL_TOP}
            ${RTL_ACCEL}

    COMMAND make
            -C ${VERILATOR_BUILD}
            -f Vmnv2_depthwise_cfu.mk

    BYPRODUCTS
            ${VERILATOR_BUILD}/Vmnv2_depthwise_cfu__ALL.a

    DEPENDS
            ${RTL_TOP}
            ${RTL_ACCEL}

    VERBATIM
)


add_library(mnv2_depthwise_cfu SHARED

    ${CMAKE_CURRENT_SOURCE_DIR}/sim_main.cpp

    ${RENODE_API}/cfu.cpp

    ${RENODE_API}/renode_cfu.cpp
)


add_dependencies(
    mnv2_depthwise_cfu
    verilate
)


target_include_directories(
    mnv2_depthwise_cfu
    PRIVATE

    ${RENODE_API}

    ${RENODE_API}/buses

    /opt/renode/plugins/IntegrationLibrary/src
    /opt/renode/plugins/IntegrationLibrary/src/buses

    ${VERILATOR_BUILD}

    /usr/share/verilator/include
    /usr/share/verilator/include/vltstd
)


target_link_libraries(
    mnv2_depthwise_cfu
    PRIVATE

    ${VERILATOR_BUILD}/Vmnv2_depthwise_cfu__ALL.a

    ${VERILATOR_BUILD}/libverilated.a

    Threads::Threads

    dl

    atomic
)
