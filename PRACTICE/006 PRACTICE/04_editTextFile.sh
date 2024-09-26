#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

filename=$1

if [ ! -f "$filename" ]; then
    echo "File not found!"
    exit 1
fi

sort "$filename" >sorted_output.txt

echo "The lines have been sorted and saved to sorted_output.txt."
