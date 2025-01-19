#!/bin/bash


read -p "Enter the two numbers: " num1 num2

echo "Before Swapping"
echo "num1=$num1, num2=$num2"

num1=$(($num1+$num2))
num2=$(($num1-$num2))
num1=$(($num1-$num2))

echo "After Swapping"
echo "num1=$num1, num2=$num2"
