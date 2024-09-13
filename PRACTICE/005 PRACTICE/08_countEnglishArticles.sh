#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -eq 1 ]; then
    echo "Total Number of English language articles (a, an, the) are: $(grep -o -i '\ba\b\|\ban\b\|\bthe\b' "$1" | wc -l)"
else
    echo "Usage: $0 filename"
fi
