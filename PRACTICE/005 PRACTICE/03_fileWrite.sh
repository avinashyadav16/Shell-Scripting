#!/bin/bash
# Avinash Yadav | AP22110010366
# Usage: ./even_odd.sh inputfile
# This script splits the content of the input file into even-numbered lines (saved in evenfile.txt)
# and odd-numbered lines (saved in oddfile.txt).

if [ $# -eq 1 ]; then
    # Create or empty the files if they already exist
    touch evenfile.txt oddfile.txt
    > evenfile.txt
    > oddfile.txt

    # Use awk to split the even and odd lines into the correct files with .txt extension
    awk 'NR % 2 == 0 { print > "evenfile.txt" } NR % 2 == 1 { print > "oddfile.txt" }' "$1"

    echo "Lines have been separated into evenfile.txt and oddfile.txt."
else
    echo "Usage: $0 filename"
fi