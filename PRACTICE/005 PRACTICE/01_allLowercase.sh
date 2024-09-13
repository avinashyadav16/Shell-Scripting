#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -eq 1 ]; then
    if [ -f "$1" ]; then
        tr '[:lower:]' '[:upper:]' <"$1"
    else
        echo "Error: File '$1' not found."
    fi
else
    echo "Usage: $0 filename"
fi
