#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# sudo ps -ef | grep "openvpn" | awk '{print $2}' | xargs kill

if [ -f ./pid/vproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' ./pid/vproxy | bash
	rm ./pid/vproxy
fi
