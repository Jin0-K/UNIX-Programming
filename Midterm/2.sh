#!/bin/bash

i=0
j=1

while (( i<100 ))
do
	#print i
	echo $i

	(( k=i+j ))
	(( i=j ))
	(( j=k ))
done

