#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter the filename: " filename

while IFS= read -r line; do
    num_chars=$(echo -n "$line" | wc -c)
    num_words=$(echo "$line" | wc -w)
    echo "$num_chars characters, $num_words words"
done <"$filename"