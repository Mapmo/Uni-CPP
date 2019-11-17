#!/bin/bash

function get()
{
	egrep "$1" "test.cpp" | egrep "[^-][[:digit:]]);" | head -1 | egrep -o "\".*\", ?[[:digit:].]*);$" | sed 's/,[^,]*$//'
}

YELLOW='\033[1;33m'
NC='\033[0m'
PINK='\033[1;35m'

echo

while read a
do

	echo -en "$a ${YELLOW}<-->${NC} " #separator
	echo -e "${PINK}$(get $(echo $a | egrep -o "^[^(]*" | egrep -o "[q|w][[:digit:]]*$" ))${NC}"  #add dakata's letter to the last egrep regex
	echo

done< <(egrep -i ".*Question.*$1" "test.cpp")

echo
