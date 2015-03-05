#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

if [ -f $allproxy_path/pid/dproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' $allproxy_path/pid/dproxy | bash
	rm $allproxy_path/pid/dproxy
fi
