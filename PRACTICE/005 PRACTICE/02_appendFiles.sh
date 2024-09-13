#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -eq 4 ]; then
    cat "$1" "$2" "$3" >"$4"
    echo "The Total Word Count is: $(wc -w <"$4")"
else
    echo "Usage: $0 file1 file2 file3 outputfile"
fi