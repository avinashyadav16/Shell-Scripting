#!/bin/bash

# 3. Write a shell script that accepts two directory names as arguments and deletes
# those files in the first directory which are similarly named in the second directory.
# Note: Contents should also match inside the files.

# Ensure both directory arguments are provided
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Error: Two directory arguments are required."
    echo "Usage: $0 <directory1> <directory2>"
    exit 1

fi

# Assign the first and second arguments (directory names) to variables 'dir1' and 'dir2'
dir1=$1
dir2=$2

# Check if the first directory exists
if [ ! -d "$dir1" ]; then
    echo "Error: Directory $dir1 does not exist."
    exit 1

fi

# Check if the second directory exists
if [ ! -d "$dir2" ]; then
    echo "Error: Directory $dir2 does not exist."
    exit 1

fi

# Flag to check if any files were deleted
files_deleted=false

# Loop through all files in 'dir1'
for file in "$dir1"/*; do
    # Check if it is a regular file (ignore directories or other non-file types)
    if [ -f "$file" ]; then
        # Check if a file with the same name exists in 'dir2'
        if [ -f "$dir2/$(basename "$file")" ]; then
            # Compare the contents of the two files using the 'cmp' command
            # cmp -s compares the files silently (without output), returning true if they match
            if cmp -s "$file" "$dir2/$(basename "$file")"; then
                # If the files match, delete the file from 'dir1'
                rm "$file"
                # Print the name of the deleted file
                echo "Deleted matching file: $(basename "$file")"
                # Set the flag to true
                files_deleted=true

            fi

        fi

    fi

done

# If no files were deleted, provide feedback
if [ "$files_deleted" = false ]; then
    echo "No matching files were found to delete."
fi
