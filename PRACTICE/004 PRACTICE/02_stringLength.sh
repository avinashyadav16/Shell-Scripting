#!/bin/bash

# 2. Write a shell script to echo the string length of the given string as argument.

# Assign the first argument passed to the script to the variable 'str'
str=$1

# Print the length of the string using ${#str} to calculate the number of characters
# ${#str} returns the length of the string stored in 'str'
echo "The length of the string $str is ${#str} characters."
