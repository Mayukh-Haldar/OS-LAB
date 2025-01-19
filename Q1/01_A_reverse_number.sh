#!/bin/bash

read -p "Enter a number: " num
revNum=0

while [[ $num -ne 0 ]]
do
	let last_digit=$((num%10))
	revNum=$((revNum*10+last_digit))
	num=$((num/10))
done

echo "The reversed number is $revNum."
