#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment

if [ -f $allproxy_path/pid/fproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' $allproxy_path/pid/fproxy | bash
	
	rm $allproxy_path/pid/fproxy
fi
sudo fuser -k 12121/tcp