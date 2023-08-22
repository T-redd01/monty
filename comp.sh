#!/bin/bash
flags="-Wall -Werror -Wextra -pedantic -std=c89"
name="monty"

if [ $# -gt 0 ]
then
	if [ $1 -eq 1 ]
	then
		echo "debug mode"
		if [ $# -eq 1 ]
		then
			gcc *.c -o $name 2> errfile
		else
			echo "capture from 2"
			#gcc "${@:2}" -o $name 2> errfile
		fi
	fi
else
	echo "Making program"
	gcc $flags *.c -o $name 2> errfile
fi

if [ $? -ne 0 ]
then
	echo "ERRORS ENCOUNTERED"
	echo "========================================================================"
	echo
	cat errfile
	echo
	echo "========================================================================\n"
else
	echo "Compiled successfully..."
fi

