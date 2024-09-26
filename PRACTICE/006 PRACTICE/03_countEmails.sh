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

unique_domains=$(awk -F '@' '{print $2}' "$filename" | sort | uniq | wc -l)

echo "Number of unique domains: $unique_domains"
