#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

while true
do
	while IFS=| read ip filename port kind;do
	    echo "ip: " ip >> $allproxy_path/log/fproxy
	    echo "filename: " filename >> $allproxy_path/log/fproxy
	    echo "port: " port >> $allproxy_path/log/fproxy
	    echo "kind: " kind >> $allproxy_path/log/fproxy
	    
	done < fproxy/cmdin
	sleep 5
	if [ ! -f  $allproxy_path/pid/fproxy ]; then
		kill $$
	fi
done