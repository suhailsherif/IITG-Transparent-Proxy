#!/bin/bash
source /etc/environment

# Killing fake DNS server, if running
sudo fuser -k 55/udp
sudo killall -I redsocks
sleep 0.1

echo "Tproxy" > $allproxy_path/log/tproxy

# sudo chmod +x $allproxy_path/redsocks/redsocks

echo "Getting variables ..." >> $allproxy_path/log/tproxy
source $allproxy_path/config/config.sh #&
echo "Configuring iptables ..." >> $allproxy_path/log/tproxy
. $allproxy_path/config/script start #& 
echo "Configuring routes ..." >> $allproxy_path/log/tproxy
source $allproxy_path/config/config_routes.sh >> $allproxy_path/log/config_routes #&

if [ ! -f $allproxy_path/redsocks/redsocks ] 
then
	sudo chmod +x $allproxy_path/redsocks/redsocks
	echo "Could not compile redsocks." >> $allproxy_path/log/tproxy
	echo "Exit On Error !" >> $allproxy_path/log/tproxy
	exit
else
	echo "make redsocks successful" >> $allproxy_path/log/tproxy 
fi

echo "Configuring redsocks ..." >> $allproxy_path/log/tproxy
. $allproxy_path/config/redsocksConfig.sh $tproxy_server $tproxy_port $tproxy_username $tproxy_password > $allproxy_path/log/Redsocks.log 2>&1 & 
echo "redsocks configured successfully" >> $allproxy_path/log/tproxy 

echo "initiating fake DNS server ..."
sudo python -u fakeDNS.py > $allproxy_path/log/DNS.log 2>&1 & 
echo "DNS server initiated" >> $allproxy_path/log/tproxy 

echo $! > $allproxy_path/pid/tproxy #&

echo "Transparent proxy initiated, running in background" >> $allproxy_path/log/tproxy 

echo "Done !!"

