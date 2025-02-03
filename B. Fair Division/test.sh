#!/bin/bash

# Ensure input file is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

INPUT_FILE="$1"
OUTPUT_LOG="output.log"

echo "Running ./a.out with input: $INPUT_FILE"

./a.out < "$INPUT_FILE" &> "$OUTPUT_LOG"


