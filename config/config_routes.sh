#!/bin/bash

source ./config/config.sh #&

echo "setting default gateway to " $nproxy_gateway
sudo ip route add to 202.141.80.0/23 via $nproxy_gateway
def_gate=$(/sbin/ip route | awk '/default/ { print $3 }')
if [ ! "$def_gate" == "$proxy_gateway" ]
then
	sudo ip route del default
	sudo ip route add default via $nproxy_gateway
fi