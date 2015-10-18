#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/allproxy/config
source $allproxy_path/config/config.sh

# sudo ps -ef | grep "openvpn" | awk '{print $2}' | xargs kill

if [ -f $allproxy_path/pid/vproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' $allproxy_path/pid/vproxy | bash
	rm $allproxy_path/pid/vproxy
fi
