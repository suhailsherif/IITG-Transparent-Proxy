#!/bin/bash
source /etc/environment
source $allproxy_path/config/config.sh

chown root:root -R /var/log
chmod 777 -R /var/log

# Killing fake DNS server, if running
sudo fuser -k 55/udp
sudo killall -I redsocks
sleep 0.1

echo "Tproxy" > $allproxy_path/log/tproxy

echo "Getting variables ..." >> $allproxy_path/log/tproxy
source $allproxy_path/config/config.sh #&
echo "Configuring iptables ..." >> $allproxy_path/log/tproxy
. $allproxy_path/tproxy/script start #& 
echo "Configuring routes ..." >> $allproxy_path/log/tproxy
source $allproxy_path/config/config_routes.sh >> $allproxy_path/log/config_routes #&

echo "Configuring redsocks ..." >> $allproxy_path/log/tproxy
. $allproxy_path/config/redsocks_config.sh $tproxy_server $tproxy_port $tproxy_username $tproxy_password > $allproxy_path/log/redsocks 2>&1 & 
echo "redsocks configured successfully" >> $allproxy_path/log/tproxy 

echo "initiating fake DNS server ..."
sudo python -u $allproxy_path/tproxy/fake_dns.py $allproxy_path/pid/tproxy > $allproxy_path/log/dns 2>&1 & 
echo "DNS server initiated" >> $allproxy_path/log/tproxy 

# echo $! > $allproxy_path/pid/tproxy #&

echo "Transparent proxy initiated, running in background" >> $allproxy_path/log/tproxy 

echo "Done !!"

