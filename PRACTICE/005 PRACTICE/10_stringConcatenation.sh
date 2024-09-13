#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -eq 2 ]; then
    result="$1$2"
    echo "First Sting: $1"
    echo "Second Sting: $2"
    echo "Concatenated String: $result"
    echo "Length: ${#result}"
else
    echo "Usage: $0 string1 string2"
fi
