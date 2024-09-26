#!/bin/bash
# Avinash Yadav | AP22110010366

echo "Enter The Two Numbers And An Operator: "
read -r num1 num2 operator

if [ "$operator" == "+" ]; then
    echo "$num1 + $num2 = $((num1 + num2))"
elif [ "$operator" == "-" ]; then
    echo "$num1 - $num2 = $((num1 - num2))"
elif [ "$operator" == "*" ]; then
    echo "$num1 * $num2 = $((num1 * num2))"
elif [ "$operator" == "/" ]; then
    echo "$num1 / $num2 = $((num1 / num2))"
else
    echo "Invalid operator"
fi
