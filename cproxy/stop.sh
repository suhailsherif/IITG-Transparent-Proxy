#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/allproxy/config
source $allproxy_path/config/config.sh

if [ -f $allproxy_path/pid/cproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' $allproxy_path/pid/cproxy | bash
	rm $allproxy_path/pid/cproxy
	
fi
