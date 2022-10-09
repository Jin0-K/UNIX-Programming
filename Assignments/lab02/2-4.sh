#!/bin/bash

echo -n "Is is morning?"
read answer
case $answer in 
	# answers start with y or Y
	y* | Y* ) echo Good Morning ;;
	# answers start with n or N
	n* | N* ) echo Have a good day ;;
	# others
	*) echo Sorry your answer is not proper ;;
esac

exit 0
