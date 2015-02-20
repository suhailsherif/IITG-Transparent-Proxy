#!/bin/bash
echo "setting default gateway to " $proxy_gateway
sudo ip route add to 202.141.80.0/23 via $proxy_gateway
def_gate=$(/sbin/ip route | awk '/default/ { print $3 }')
if [ ! def_gate eq $proxy_gateway ]
then
	sudo ip route del default
	sudo ip route add default via $proxy_gateway
fi