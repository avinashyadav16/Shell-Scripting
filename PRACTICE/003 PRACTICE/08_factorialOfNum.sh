#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter a number: " number

factorial=1

for ((i = 2; i <= number; i++)); do
    factorial=$((factorial * i))
done

echo "The factorial of $number is $factorial"