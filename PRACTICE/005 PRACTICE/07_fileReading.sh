#!/bin/bash
# Avinash Yadav | AP22110010366

echo -n "Enter the file name: "
read -r filename

if [ -f "$filename" ]; then
    lines_per_page=15
    lines=$(wc -l <"$filename")
    for ((i = 1; i <= lines; i += lines_per_page)); do
        head -n $((i + lines_per_page - 1)) "$filename" | tail -n $lines_per_page
        echo -n "Press any key to continue..."
        read -r -n 1
    done
else
    echo "File not found!"
fi