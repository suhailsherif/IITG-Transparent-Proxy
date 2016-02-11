#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment

if [ ! -f $allproxy_path/pid/$1 ]; then
	echo "off"
else
	read pid < $allproxy_path/pid/$1
	if [[ -z "$pid" ]]; then
 			echo "off"
	else
		if ps -p $pid > /dev/null; then
		   echo "on"
		else
			echo "off"
		fi
	fi
fi
