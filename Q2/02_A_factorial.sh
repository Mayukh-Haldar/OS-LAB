#!/bin/bash


read -p "Enter a number: " num
fact=1

if [[ $num -lt 0 ]]
then
	echo "Please enter a non-negative integer."
else
	for(( i=1;i<=num;i++ ))
	do
        	fact=$((fact*i));
	done
	echo "Factorial of $num is $fact."; 
fi
