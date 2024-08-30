#!/bin/bash
# Avinash Yadav | AP22110010366

# Command line arguments
num1=$1
num2=$2
num3=$3

# Find the greatest number
if [ "$num1" -ge "$num2" ] && [ "$num1" -ge "$num3" ]; then
    greatest=$num1
elif [ "$num2" -ge "$num1" ] && [ "$num2" -ge "$num3" ]; then
    greatest=$num2
else
    greatest=$num3
fi

echo "The greatest number is $greatest"