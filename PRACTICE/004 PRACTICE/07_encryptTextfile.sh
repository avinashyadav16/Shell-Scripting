#!/bin/bash

# 7. Write a shell script to encrypt any text file.

# Assign the first argument (file name) to the variable 'file'
file=$1

# Check if the provided argument is a valid file
if [ -f "$file" ]; then
    # If the file exists, use the 'gpg -c' command to encrypt the file
    # The '-c' option stands for "symmetric encryption," which uses a passphrase
    gpg -c "$file"
    
else
    # If the file doesn't exist, print an error message
    echo "File does not exist."

fi
