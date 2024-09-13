#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -eq 1 ]; then
    awk 'NR % 2 == 1' "$1" > temp && mv temp "$1"
else
    echo "Usage: $0 filename"
fi
