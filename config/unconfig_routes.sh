#!/bin/bash
source /etc/environment
source $allproxy_path/config/config.sh

sudo ip route del 202.141.80.0/23 via $nproxy_gateway

def_gateway=$(/sbin/ip route | awk '/default/ { print $3 }')

# echo $restore_gateway
# echo $def_gateway

if [ ! "$restore_gateway" == "$def_gateway" ]
then
	sudo ip route del default
	sudo ip route add default via $restore_gateway
fi
