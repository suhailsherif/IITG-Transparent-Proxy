#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# Please run as root.
# Usage: bash findport.sh 3000 100
#
 
 
if [[ -z "$1" || -z "$2" ]]; then
  echo "Usage: $0 <base_port> <increment>"
  exit 1
else 
	if [[ $2 -eq 0 ]]; then
		exit 1
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
exit 0