#!/bin/bash

# 6. Write a shell script to check the spellings of any text document given as an argument.

# Assign the first argument (file name) to the variable 'file'
file=$1

# Check if the provided argument is a valid file
if [ -f "$file" ]; then
    # If the file exists, use the 'aspell list' command to find misspelled words
    # 'aspell list' prints words that are not recognized by the dictionary
    echo "The Wrong Words are: "
    aspell list <"$file"

else
    # If the file doesn't exist, print an error message
    echo "File does not exist."

fi
