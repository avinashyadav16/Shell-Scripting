#!/bin/bash

# 10. Write a shell script that changes the name of the files passed as arguments to lowercase.

# Loop through all the arguments passed to the script
for file in "$@"; do
    # Use 'mv' to rename the file
    # 'echo "$file" | tr '[:upper:]' '[:lower:]'' converts the filename to lowercase
    mv "$file" "$(echo "$file" | tr '[:upper:]' '[:lower:]')"
done
