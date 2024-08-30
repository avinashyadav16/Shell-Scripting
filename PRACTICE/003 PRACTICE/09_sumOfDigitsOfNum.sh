#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter a number: " number

sum_of_digits=0

while [ "$number" -gt 0 ]; do
    digit=$((number % 10))
    sum_of_digits=$((sum_of_digits + digit))
    number=$((number / 10))
done

echo "The sum of the digits is $sum_of_digits"