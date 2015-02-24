#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# sudo ps -ef | grep "ssh" | awk '{print $2}' | xargs kill

if [ -f ./pid/sproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' ./pid/sproxy | bash
	rm ./pid/sproxy
fi
