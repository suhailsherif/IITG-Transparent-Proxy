#!/bin/bash

sudo ip route del 202.141.80.0/23 via $nproxy_gateway
def_gateway=$(/sbin/ip route | awk '/default/ { print $3 }')
source ./config/config.sh
echo $restore_gateway
echo $def_gateway
if [ ! "$restore_gateway" == "$def_gateway" ]
then
	sudo ip route del default
	sudo ip route add default via $restore_gateway
fi
