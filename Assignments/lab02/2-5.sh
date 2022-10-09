#!/bin/bash

#function that returns the addition of two arguments
sum(){
	((sum = $1 + $2))
	return $sum
}

sum 10 20
echo The result is $?

exit 0
