#!/bin/bash

###########################################################################################################################################################
################################################################# About UNIX ##############################################################################
###########################################################################################################################################################

# • Commands are typed at a prompt.
#       Most often, the prompt is a percent sign (%) or dollar sign ($) but sometimes it is the name of the machine followed by the percent or dollar sign.

# • Commands are case sensitive and are usually lower case.
#       This means that ls and LS are completely different commands.

# • Spaces are very important.
#       There is always a space between the command and the file or directory it acts upon.

# • To execute a UNIX command, press Enter at the end of the command line.
#       If the command is accepted, the prompt and cursor will simply appear on the next line awaiting your next command.
#       If the command is rejected, an error message such as "Command not found" appears.
#       To negate a command before you have pressed Enter, press CTRL + C.

# • To determine your default shell, type echo $SHELL.

# • To change your default shell, run /usr/local/bin/chsh and follow the prompt.
#       Do NOT use flags on the command. This is a custom script and not the standard chsh you might find on Linux machines.
#       After running the command, allow 24 hours for the default shell to take effect.

# • Dot files begin with a dot (.) and are used primarily to control system functions.
#       Unless you are an advanced UNIX user, you should not add or delete anything from a dot file.

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
