#!/bin/bash

# 8. Combine the above commands in a shell script so that you have a small program for extracting a wordlist.

# Assign the first argument (file name) to the variable 'file'
file=$1

# Check if the provided argument is a valid file
if [ -f "$file" ]; then
    # Use 'aspell list' to find misspelled words and pipe the output to 'sort -u' to get unique entries
    # Redirect the sorted unique words to 'wordlist.txt'
    aspell list <"$file" | sort -u >wordlist.txt
    # Print a message indicating where the wordlist was saved
    echo "Wordlist extracted to wordlist.txt."

else
    # If the file doesn't exist, print an error message
    echo "File does not exist."

fi
