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

vowels=$(grep -o -i '[aeiou]' "$filename" | wc -l)

spaces=$(grep -o ' ' "$filename" | wc -l)

characters=$(wc -m <"$filename")

lines=$(wc -l <"$filename")

symbols=$(grep -o '[^a-zA-Z0-9 ]' "$filename" | wc -l)

echo "Number of vowels: $vowels"
echo "Number of blank spaces: $spaces"
echo "Number of characters: $characters"
echo "Number of lines: $lines"
echo "Number of symbols: $symbols"
