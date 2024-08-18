#!/bin/bash

# 1. List all the files and directories
ls

# 2. Check system date and time
date

# 3. Create a Parent called Sports
mkdir Sports

# 4. Create text files called Team1.txt, Team2.txt and Team3.txt in the Sports directory.
touch

# 5. Create a sub-directory Cricket in Sports directory
mkdir Cricket

# 6. Create a sub-directory Hockey in Sports directory
mkdir Hockey

# 7. Create a sub-directory Football in Sports directory
mkdir Football

# 8. Rename the directory Hockey to Badminton
mv Hockey Badminton

# 9. Create one text file Sample.txt in Badminton, Football, and Cricket sub-directories.
touch Badminton/Sample.txt Football/Sample.txt Cricket/Sample.txt

# 10. Move to the Badminton directory and change the name of Sample.txt to BadmintonTeam.txt
cd Badminton
mv Sample.txt BadmintonTeam.txt

# 11. Display the number of lines in Team1.txt
wc -l Team1.txt

# 12. Display the first 3 lines of Team2.txt
head -n 3 Team2.txt

# 13. Display the concatenated contents of Team2.txt and Team3.txt
cat Team2.txt Team3.txt

# 14. Display the number of lines in Team1.txt (again)
wc -l Team1.txt

# 15. Remove all the text files in the Sports directory
rm *.txt

# 16. Copy all the contents of the Badminton directory to another directory called Game
mkdir Game
cp -r Badminton/* Game

# 17. Remove the Badminton directory
rm -r Badminton
