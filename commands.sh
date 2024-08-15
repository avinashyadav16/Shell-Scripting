#!/bin/bash

###########################################################################################################################################################
############################################################## Common UNIX Commands #######################################################################
###########################################################################################################################################################

# Make a directory:       mkdir <directory>
mkdir testDirectory

# Change directories:       cd <directory>
# cd testDirectory

# Prints contents of file in the command window:       cat <file>
cat commands.sh

# Copy the contents of file into file2:       cp <file> <file2>
cp commands.sh copiedFile.sh

# List the files and subdirectories in a directory
ls

# List the difference between files and directories--directories have a slash (/)
ls -F

# List files with status/detail information
ls -l

# List file information in long format, sorted by time with newest files or newly changed files appearing first
ls -lt

# List all the files in a directory including dot files
ls -a

# Lists AFS quota, space used, percentage used (if applicable)
# fs lq

# Lists percentage of quota used (if applicable)
# fs q

# Move file to file2
# mv <file> <file2>

# Print the pathname of the current directory
pwd

# Create a new file called newfile.sh
touch newfile.sh

# Remove or delete files:       rm <file>
rm newfile.sh

# Remove directory:       rmdir <directory>
rmdir testDirectory

# List history of all commands issued at system prompt
history
