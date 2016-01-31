#!/bin/bash

# run inside tproxy folder
cd "$(dirname "$0")"

source /etc/allproxy/config
source $allproxy_path/config/config.sh

if [ -z ${allproxy_path+x} ]; then 
	echo "allproxy_path is unset. set and try again."
	exit 1 
fi

if [ -f $allproxy_path/config/config.sh ]; then
	source $allproxy_path/config/config.sh
else
	echo "config file not found. Aborting."
	exit 1
fi

sudo chown root:root -R /var/log
sudo chmod 777 -R /var/log

# Killing redsocks, if running
if pgrep "redsocks" > /dev/null
then
    sudo killall -I redsocks
fi

# Killing fake DNS server, if running
sudo fuser -k 55/udp

# if pgrep "dnsmasq" > /dev/null
# then
#     sudo killall dnsmasq
# fi
# sleep 0.1

echo "Tproxy" > $allproxy_path/log/tproxy

echo "Getting variables ..." >> $allproxy_path/log/tproxy
source $allproxy_path/config/config.sh #&

echo "Configuring iptables ..." >> $allproxy_path/log/tproxy
. $allproxy_path/tproxy/script start #& 

echo "Configuring redsocks ..." >> $allproxy_path/log/tproxy
. $allproxy_path/config/redsocks_config.sh $tproxy_server $tproxy_port $tproxy_username $tproxy_password > $allproxy_path/log/redsocks 2>&1 & 
echo "redsocks configured successfully" >> $allproxy_path/log/tproxy 

echo "initiating fake DNS server ..." >> $allproxy_path/log/tproxy

command -v python >/dev/null 2>&1 || { echo >&2 "\"python\" required but it's not installed.  Aborting."; exit 1; }

sudo python -u $allproxy_path/tproxy/fake_dns.py $allproxy_path/pid/tproxy $allproxy_path/tproxy > $allproxy_path/log/dns 2>&1 & 
echo "DNS server initiated" >> $allproxy_path/log/tproxy 

echo "Starting dnsmasq on all open interfaces ..." >> $allproxy_path/log/tproxy

# command -v netmask >/dev/null 2>&1 || { echo >&2 "\"netmask\" required but it's not installed.  Aborting."; exit 1; }
command -v dnsmasq >/dev/null 2>&1 || { echo >&2 "\"dnsmasq\" required but it's not installed.  Aborting."; exit 1; }

# if pgrep "dnsmasq" > /dev/null
# then
#     sudo dnsmasq
# fi

echo "Transparent proxy initiated, running in background" >> $allproxy_path/log/tproxy 

echo "Done !!"

exit
