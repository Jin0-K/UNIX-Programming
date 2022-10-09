#!/bin/bash

op1=2

while (( op1<10 ))
do
	op2=1

	while (( op2<10))
	do
		echo -n -e "$(( op1*op2 ))\t"
		(( op2+=1 ))
	done
	
	echo '' 
	(( op1+=1 ))
done
