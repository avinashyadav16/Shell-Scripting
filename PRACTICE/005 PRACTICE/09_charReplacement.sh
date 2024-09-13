#!/bin/bash
# # Avinash Yadav | AP22110010366

# if [ $# -eq 3 ]; then
#     replaced_string=$(echo "$1" | sed "s/$2/$3/g")  
#     echo "Original string: $1"
#     count=$(echo "$1" | grep -o "$2" | wc -l)
#     echo "Replaced string: $replaced_string"
#     echo "Number of replacements: $count"
# else
#     echo "Usage: $0 string char replacement"
# fi


#!/bin/bash
# Avinash Yadav | AP22110010366

if [ $# -eq 3 ]; then
    original_string="$1"
    search_char="$2"
    replacement_char="$3"

    replaced_string="${original_string//"$search_char"/"$replacement_char"}"
    count=$(grep -o "$search_char" <<< "$original_string" | wc -l)

    echo "Original string: $original_string"
    echo "Replaced string: $replaced_string"
    echo "Number of replacements: $count"
else
    echo "Usage: $0 string char replacement"
fi
