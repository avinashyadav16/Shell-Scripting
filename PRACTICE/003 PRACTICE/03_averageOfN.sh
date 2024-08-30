#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter numbers separated by space: " -a numbers

sum=0
for num in "${numbers[@]}"; do
    sum=$((sum + num))
done

average=$((sum / ${#numbers[@]}))

echo "The average is $average"