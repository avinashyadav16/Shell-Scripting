#!/bin/bash

# 9. Write a shell script which reads the contents in a text file and removes all the blank spaces in them and redirects the output to a file.

# Assign the first argument (input file name) to the variable 'input_file'
input_file=$1

# Assign the second argument (output file name) to the variable 'output_file'
output_file=$2

# Check if the provided input file is a valid file
if [ -f "$input_file" ]; then
    # Use 'sed' to remove all blank spaces from the input file
    # The 's/ //g' expression replaces all spaces with nothing (effectively removing them)
    # Redirect the output to the specified output file
    sed 's/ //g' "$input_file" >"$output_file"
    # Print a message indicating that the spaces have been removed and output saved
    echo "Spaces removed and output saved to $output_file."

else
    # If the input file doesn't exist, print an error message
    echo "Input file does not exist."

fi
