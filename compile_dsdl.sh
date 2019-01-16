#!/bin/sh

# MUST be run in this directory

# Settings
LIBCANARD_CMD="libcanard/dsdl_compiler/libcanard_dsdlc"
LIBCANARD_OUTDIR="libcanard_dsdlc_generated"

LIBUAVCAN_CMD="libuavcan/libuavcan/dsdl_compiler/libuavcan_dsdlc"
LIBUAVCAN_OUTDIR="libuavcan_dsdlc_generated"

DSDL_INPUT="spear/ uavcan_dsdl/uavcan/"

# Actually run the commands
echo "Compiling DSDL..."
${LIBCANARD_CMD} --outdir ${LIBCANARD_OUTDIR} ${DSDL_INPUT} && \
${LIBUAVCAN_CMD} --outdir ${LIBUAVCAN_OUTDIR} ${DSDL_INPUT}
