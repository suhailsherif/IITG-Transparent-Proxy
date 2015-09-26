#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment
source $allproxy_path/config/config.sh

sudo ps -ef | grep "privoxy" | awk '{print $2}' | xargs kill

if [ -f $allproxy_path/pid/lproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' $allproxy_path/pid/lproxy | bash
	rm $allproxy_path/pid/lproxy
	
fi
