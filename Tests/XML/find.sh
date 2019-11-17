#!/bin/bash

function get()
{
	egrep "$1" "test.cpp" | egrep "[^-][[:digit:]]);" | head -1 | egrep -o "\".*\", ?[[:digit:].]*);$" | sed 's/,[^,]*$//'
}

while read a
do

	echo -n "$a ::: " #separator
	get $(echo $a | egrep -o "^[^(]*" | egrep -o "[q|w][[:digit:]]*$" ) #add dakata's letter to the last egrep regex

done< <(egrep --color=auto -i ".*Question.*$1" "test.cpp")


