#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# Please run as root.
# Usage: bash findport.sh 3000 100
#
 
 
if [[ -z "$1" || -z "$2" ]]; then
  echo "0"
else 
	if [[ $2 -eq 0 ]]; then
		echo "0"
	fi
fi
 
 
BASE=$1
INCREMENT=$2
 
port=$BASE
isfree=$(netstat -tapln | grep $port)
 
while [[ -n "$isfree" ]]; do
  port=$[port+INCREMENT]
  isfree=$(netstat -tapln | grep $port)
done
 
echo "$port"