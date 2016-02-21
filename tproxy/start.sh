#!/bin/bash

# Killing fake DNS server, if running
sudo fuser -k 55/udp
sudo killall -I redsocks
sleep 0.1

echo "Tproxy" > ./log/tproxy

# sudo chmod +x ./redsocks/redsocks

echo "Getting variables ..." >> ./log/tproxy
source ./config/config.sh #&
echo "Configuring iptables ..." >> ./log/tproxy
. ./config/script start #& 
echo "Configuring routes ..." >> ./log/tproxy
source ./config/config_routes.sh >> ./log/config_routes #&

if [ ! -f ./redsocks/redsocks ] 
then
	echo "make redsocks initiating ..." >> ./log/tproxy 
	make -C ./redsocks/ >> ./log/tproxy
fi

if [ ! -f ./redsocks/redsocks ] 
then
	sudo chmod +x ./redsocks/redsocks
	echo "Could not compile redsocks." >> ./log/tproxy
	echo "Exit On Error !" >> ./log/tproxy
	exit
else
	echo "make redsocks successful" >> ./log/tproxy 
fi

echo "Configuring redsocks ..." >> ./log/tproxy
. ./config/redsocksConfig.sh $tproxy_server $tproxy_port $tproxy_username $tproxy_password > ./log/Redsocks.log 2>&1 & 
echo "redsocks configured successfully" >> ./log/tproxy 

echo "initiating fake DNS server ..."
sudo python -u fakeDNS.py > ./log/DNS.log 2>&1 & 
echo "DNS server initiated" >> ./log/tproxy 

echo $! > ./pid/tproxy #&

echo "Transparent proxy initiated, running in background" >> ./log/tproxy 