#!/bin/bash
# Avinash Yadav | AP22110010366

for dir in */; do
    count=$(find "$dir" -type f | wc -l)
    echo "Total Number of files in $dir: $count files"
done