#!/bin/sh

array=(12 5 7 2 11 20 9 13 11)
size=${#array[@]}

for((i=0;i<size-1;i++))
do
	min=${array[$i]}
	index=$i
	for((j=i+1;j<size;j++))
	do
		if((min>array[j]))
		then
			min=${array[$j]}
			index=$j;
		fi
	done
	temp=${array[$i]}
	array[$i]=${array[$index]}
	array[$index]=$temp
done
for((i=0;i<size;i++))
do
	echo ${array[$i]}
done
