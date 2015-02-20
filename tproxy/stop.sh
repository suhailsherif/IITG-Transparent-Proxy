#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

. ./config/script stop
# sudo ps -ef | grep "redsocks" | awk '{print $2}' | xargs kill

if [ -f ./pid/tproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' ./pid/tproxy | bash
	rm ./pid/tproxy
fi
