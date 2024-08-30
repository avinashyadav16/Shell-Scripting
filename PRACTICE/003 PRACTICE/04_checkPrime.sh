#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter a number: " number

is_prime=1
if [ "$number" -le 1 ]; then
    is_prime=0
else
    for ((i = 2; i * i <= number; i++)); do
        if [ $((number % i)) -eq 0 ]; then
            is_prime=0
            break
        fi
    done
fi

if [ $is_prime -eq 1 ]; then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi