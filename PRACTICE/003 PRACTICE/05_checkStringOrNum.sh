#!/bin/bash
# Avinash Yadav | AP22110010366

read -r -p "Enter Input Data: " input_data

if [[ "$input_data" =~ ^[0-9]+$ ]]; then
    echo "$input_data is a number."
else
    echo "$input_data is a string."
fi