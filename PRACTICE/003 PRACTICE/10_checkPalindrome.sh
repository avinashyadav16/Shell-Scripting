#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter a string: " string

reversed_string=$(echo "$string" | rev)

if [ "$string" == "$reversed_string" ]; then
    echo "$string is a palindrome"
else
    echo "$string is not a palindrome"
fi