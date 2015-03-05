#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

proxy_list=( "tproxy" "vproxy" "sproxy" "lproxy" "cproxy" "dproxy" )
for i in "${proxy_list[@]}"
do
	
	if [ ! "$($allproxy_path/config/status.sh $i)" = "on" ]; then
	  	if [ -f $allproxy_path/pid/$i ];
	  	then
	  		rm -rf $allproxy_path/pid/$i
	  	fi
	fi
done