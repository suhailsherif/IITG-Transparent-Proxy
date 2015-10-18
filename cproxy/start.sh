#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/allproxy/config
source $allproxy_path/config/config.sh

echo "Cproxy " > $allproxy_path/log/cproxy

cp "$allproxy_path/cproxy/server.conf.in" "$allproxy_path/cproxy/server.conf"

if [ $# -eq 0 ]; then
    # no arguments"
    sed -i "s,cproxy_ip,$cproxy_ip," $allproxy_path/cproxy/server.conf
    sed -i "s,cproxy_port,$cproxy_port," $allproxy_path/cproxy/server.conf
else
	sed -i "s,cproxy_ip,$1," $allproxy_path/cproxy/server.conf
	sed -i "s,cproxy_port,$2," $allproxy_path/cproxy/server.conf
fi


sed -i "s,cproxy_root,$allproxy_path/cproxy," $allproxy_path/cproxy/server.conf

MACHINE_TYPE=`uname -m`

if [ ${MACHINE_TYPE} == 'x86_64' ]; then
	# 64 bit
	$allproxy_path/cproxy/bin/linux_amd64 -c="$allproxy_path/cproxy/server.conf" &
	echo $! > $allproxy_path/pid/cproxy
else
	# 32 bit
	$allproxy_path/cproxy/bin/linux_386 -c="$allproxy_path/cproxy/server.conf" &
	echo $! > $allproxy_path/pid/cproxy
fi

if [ $# -eq 0 ]; then
    # no arguments"
    echo "Opening link http://$cproxy_ip:$cproxy_port"
    xdg-open "http://$cproxy_ip:$cproxy_port"
else
	echo "Opening link http://$1:$2"
	xdg-open "http://$1:$2"
fi

echo "Ensure No-proxy env in browser."


exit
