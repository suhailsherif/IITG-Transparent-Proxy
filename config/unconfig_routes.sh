#!/bin/bash
source /etc/environment
source $allproxy_path/config/config.sh

sudo ip route del 202.141.80.0/23 via $nproxy_gateway

def_gateway=$(/sbin/ip route | awk '/default/ { print $3 }')

if [[ $def_gate =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
then
	ping -W 1 -c 2 $def_gate >/dev/null
	ping -W 1 -c 2 $def_gate >/dev/null
	if [ $? -eq 0 ]
	then
		echo "Internet is up."

	else
		if [[ $restore_gateway =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
		then
			sudo ip route del default
			sudo ip route add default via $restore_gateway
		fi
	fi
fi
