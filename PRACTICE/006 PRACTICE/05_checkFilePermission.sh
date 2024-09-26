#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

filename=$1

if [ ! -e "$filename" ]; then
    echo "File does not exist!"
    exit 1
fi

if [ -r "$filename" ]; then
    echo "The file '$filename' is readable."
else
    echo "The file '$filename' is not readable."
fi

if [ -w "$filename" ]; then
    echo "The file '$filename' is writable."
else
    echo "The file '$filename' is not writable."
fi

if [ -x "$filename" ]; then
    echo "The file '$filename' is executable."
else
    echo "The file '$filename' is not executable."
fi
