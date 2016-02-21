#!/bin/bash

sudo killall -I openvpn
source ./config/config.sh

echo "VVproxy" > ./log/vproxy

echo "vproxy_path: " "$vproxy_path" >> ./log/vproxy
echo "vproxy_cred_path: " "$vproxy_cred_path" >> ./log/vproxy
echo "vproxy_server: " "$vproxy_server" >> ./log/vproxy
echo "vpnbook_cred_path: " "$vpnbook_cred_path" >> ./log/vproxy
echo "vproxy_port: " "$vproxy_port" >> ./log/vproxy
echo "vproxy_username: " "$vproxy_username" >> ./log/vproxy
echo "vproxy_password: " "$vproxy_password" >> ./log/vproxy
echo "vproxy_proxy_username: " "$vproxy_proxy_username" >> ./log/vproxy
echo "vproxy_proxy_password: " "$vproxy_proxy_password" >> ./log/vproxy

vpnbook_cred_path="/config/vpnbook_cred"
vproxy_cred_path="/config/vproxy_cred"

echo "Creating temporary files for openvpn connection ..." >> ./log/vproxy
echo "$vproxy_username" > $(pwd)$vpnbook_cred_path
echo "$vproxy_password" >> $(pwd)$vpnbook_cred_path

echo "$vproxy_proxy_username" > $(pwd)$vproxy_cred_path
echo "$vproxy_proxy_password" >> $(pwd)$vproxy_cred_path

if [ -f ./config/vpnbook_cred ] && [ -f ./config/vproxy_cred ] 
then
	echo "initiating openvpn connection ..." >> ./log/vproxy
	openvpn --config $vproxy_path --auth-user-pass $(pwd)$vpnbook_cred_path --http-proxy-timeout 5 \
		--http-proxy $vproxy_server $vproxy_port $(pwd)$vproxy_cred_path basic > ./log/openvpn.log 2>&1 & 
	sleep 0.5
	echo `ps aux | grep -F 'openvpn' | grep -v -F 'grep' | awk '{ print $2 }'` > ./pid/vproxy
	echo "removing temporary credential files ..." >> ./log/vproxy
	sudo rm -rf $(pwd)$vproxy_cred_path $(pwd)$vpnbook_cred_path 2>&1 & 
	echo "credential files removed" >> ./log/vproxy
	echo -n "Waiting for openvpn connection ..." >> ./log/vproxy

else
	echo "config files not found" >> ./log/vproxy
	echo "Exit On Error !" >> ./log/vproxy
fi
