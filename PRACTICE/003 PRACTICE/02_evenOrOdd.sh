#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter a number: " number

if [ $((number & 1)) -eq 0 ]; then
    echo "$number is Even"
else
    echo "$number is Odd"
fi