#!/bin/bash


read -p "Enter the 3 numbers: " num1 num2 num3

if [[ $num1 -gt $num2 ]]
then
	if [[ $num1 -gt $num3 ]]
	then
		echo "The maximum number is $num1"
	else
		echo "The maximum number is $num3"
	fi
else
	if [[ $num2 -gt $num3 ]]
	then
		echo "The maximum number is $num2"
	else
		echo "The maximum number is $num3"
	fi
fi
