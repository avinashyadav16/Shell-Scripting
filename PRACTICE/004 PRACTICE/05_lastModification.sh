#!/bin/bash

# 5. Write a shell script that displays the last modification time of any file.

# Assign the first argument (file name) to the variable 'file'
file=$1

# Check if the provided argument is a valid file
if [ -f "$file" ]; then
    # If the file exists, use 'stat' to get the last modification time
    # The '-c %y' option prints the last modification time in a readable format (YYYY-MM-DD HH:MM:SS)
    stat -c %y "$file"

else
    # If the file doesn't exist, print an error message
    echo "File does not exist."
    
fi
