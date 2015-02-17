#!/bin/bash

# Killing fake DNS server, if running
sudo fuser -k 55/udp
sleep 0.1

if [ ! -f ./redsocks/redsocks ] 
then
	echo "make redsocks initiating ..."
	make -C ./redsocks/
fi

if [ ! -f ./redsocks/redsocks ] 
then
	echo "Could not compile redsocks."
	echo "Exit On Error !"
	exit
else
	echo "make redsocks successful"
fi

echo "Configuring redsocks ..."
. ./config/redsocksConfig.sh $proxy_server $proxy_port $proxy_username $proxy_password > ./log/Redsocks.log 2>&1 & 
echo "redsocks configured successfully"

echo "initiating fake DNS server ..."
sudo python -u fakeDNS.py > ./log/DNS.log & 
echo "DNS server initiated"

echo $! > pidfile.temp #&

echo "Transparent proxy initiated, running in background"