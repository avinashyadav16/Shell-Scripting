#!/bin/bash

# 1. Write a shell script that accepts a string from the terminal and echo a suitable message
# if it doesn’t have at least 5 characters including the other symbols.

# Check if an argument is provided
if [ -z "$1" ]; then
    # -z "$1" checks if the first argument is an empty string
    # -z is a test condition that checks if the string is empty (zero length)
    # "$1" refers to the first argument passed to the script
    # If no argument is given, or the argument is an empty string, this condition will be true
    # If true, it will print an error message
    echo "Error: No string provided. Please provide a string as an argument."

    # Exit the script with a status code of 1 (indicating an error)
    exit 1
    
fi

# Check the length of the provided string
if [ ${#1} -lt 5 ]; then
    # ${#1} gets the length of the first argument (string)
    # Here, $1 refers to the first argument passed to the script
    # For example, if the script is run as ./script.sh hello, $1 is "hello"
    # ${#1} will return the length of the string in $1, which is 5 in this case
    # -lt 5 checks if the length is less than 5
    # If the string has fewer than 5 characters, print a message
    echo "The string should have at least 5 characters."

else
    # If the string has 5 or more characters, print a valid message
    echo "The string is valid, it has more than 5 characters."

fi
