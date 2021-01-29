#!/bin/bash

nnvg -h &> /dev/null

print_usage() {
	echo "Usage: generate_dsdl.sh [OUTPUT_DIR]"
	echo "\tOUTPUT_DIR is an optional output directory to specify"
	exit -2
}

if [[ $? != 0 ]]; then
	echo "nnvg utility not found! Please install the \`nunavut\` package in your current Python environment!"
	exit -1
fi

if [[ $# > 1 ]]; then
	print_usage
fi

if [[ $1 == "-h" || $1 == "--help" ]]; then
	print_usage
fi

if [[ $# == 1 ]]; then
	OUT="--outdir $1"
else
	OUT=""
fi

set -x
nnvg public_regulated_data_types/uavcan/ --target-language c $OUT
nnvg spear -I public_regulated_data_types/uavcan --target-language c $OUT

