#!/bin/bash

# This is a comment.


# Showing the date and time
date


# Listing out all the files and directories:
ls


# Printing a statement:
echo -e "Hello World! \n"


# System variables examples:
echo "The Home Directory is: $HOME"
echo "The User is: $USER"
echo "The Hostname is: $HOSTNAME"
echo "The Terminal is: $TERM"
echo "The Current Working Directory is: $PWD"
echo "The Shell is: $SHELL"
echo "The Path is: $PATH"
echo "The UID is: $UID"
echo "The GID is: $GID"
echo "The PPID is: $PPID"
echo "The BASH is: $BASH"
echo "The BASH_VERSION is: $BASH_VERSION"


# User-defined Variables
greetMessage="Greetings of the Day!"
name="Avinash Yadav"
echo -e "Hello, $name! $greetMessage \n"


num1=20
num2=40
# Below both the statements are fine:
echo "Method - 01: First Number is $num1 and Second Number is $num2."
echo -e Method - 02: First Number is $num1 and Second Number is $num2. "\n"

# Input operation:
echo "Enter Your Name Here: "
read -r name
echo -e "Good morning $name \n"


# Arithmetic operations-Different methods:
# Method-1:
prd1=$((10 * 5))
echo "Product of 10 and 5 is $prd1"

# Method-2:
((prd2=10 * 5))
echo "Product of 10 and 5 is $prd2"

# Method-3:
num1=10
num2=5
((prd3 = num1 * num2))
echo -e "Product of $num1 and $num2 is $prd3 \n"


# Conditional Operator:
echo "Enter a Number: "
read -r num
if [ "$num" -gt 0 ]; then
    echo -e "The number is greater than 0 \n"
elif [ "$num" -lt 0 ]; then
    echo -e "The number is less than 0 \n"
else
    echo -e "The number is 0 \n"
fi



# Checking which Number is greater:
echo "Enter The First Number: "
read -r num1
echo "Enter The Second Number: "
read -r num2

if [ "$num1" -gt "$num2" ]; then
    echo -e "First Number $num1 is Greater Than Second Number $num2. \n"
else
    echo -e "Second Number $num2 is Greater Than First Number $num1. \n"
fi


# Arrays:
lang=('C' 'CPP' 'Python' 'Rust' 'R' 'Golang')
echo "Method - 01 By Using *: Programming Languages are: ${lang[*]}"
echo "Method - 02 By Using @: Programming Languages are:" "${lang[@]}"

echo "Programming Languages at Index 3: ${lang[3]}"

echo "Programming Languages Indices are: " "${!lang[@]}"

echo "Programming Languages length is: " "${#lang[@]}"

lang[2]='PHP'
echo -e "Programming Languages are: " "${lang[@]}" "\n"


# Sum of first n numbers:
start=1
sum=0
echo "Enter The Nth Number:"
read -r cnt

while [ "$start" -le "$cnt" ]; do
    ((sum += start))
    ((start++))
done

echo "Sum of First $cnt Natural Numbers is $sum"