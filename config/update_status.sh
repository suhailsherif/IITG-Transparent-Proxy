#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/environment

proxy_list=( "tproxy" "vproxy" "sproxy" "lproxy" "cproxy" "dproxy" "fproxy" )
for i in "${proxy_list[@]}"
do
	echo $($allproxy_path/config/status.sh $i)
	if [ "$($allproxy_path/config/status.sh $i)" = "off" ]; then
	  	rm -rf $allproxy_path/pid/$i
	fi
done