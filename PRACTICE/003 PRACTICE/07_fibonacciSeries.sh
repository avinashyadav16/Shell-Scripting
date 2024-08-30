#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter the number of terms: " n

a=0
b=1

for ((i = 0; i < n; i++)); do
    echo -n "$a "
    temp=$((a + b))
    a=$b
    b=$temp
done

echo ""