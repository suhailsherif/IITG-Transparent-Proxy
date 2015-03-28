#!/bin/bash
source /etc/environment

sudo killall -I openvpn
source $allproxy_path/config/config.sh

echo "Vproxy" > $allproxy_path/log/vproxy

echo "vproxy_path: " "$vproxy_path" >> $allproxy_path/log/vproxy
echo "vproxy_cred_path: " "$vproxy_cred_path" >> $allproxy_path/log/vproxy
echo "vproxy_server: " "$vproxy_server" >> $allproxy_path/log/vproxy
echo "vpnbook_cred_path: " "$vpnbook_cred_path" >> $allproxy_path/log/vproxy
echo "vproxy_port: " "$vproxy_port" >> $allproxy_path/log/vproxy
echo "vproxy_username: " "$vproxy_username" >> $allproxy_path/log/vproxy
echo "vproxy_password: " "$vproxy_password" >> $allproxy_path/log/vproxy
# echo "vproxy_proxy_username: " "$vproxy_proxy_username" >> $allproxy_path/log/vproxy
# echo "vproxy_proxy_password: " "$vproxy_proxy_password" >> $allproxy_path/log/vproxy

vpnbook_cred_path="/config/vpnbook_cred"
vproxy_cred_path="/config/vproxy_cred"

echo "Creating temporary files for openvpn connection ..." >> $allproxy_path/log/vproxy
echo "$vproxy_username" > $(pwd)$vpnbook_cred_path
echo "$vproxy_password" >> $(pwd)$vpnbook_cred_path

echo "$vproxy_proxy_username" > $(pwd)$vproxy_cred_path
echo "$vproxy_proxy_password" >> $(pwd)$vproxy_cred_path

if [ -f $allproxy_path/config/vpnbook_cred ] && [ -f $allproxy_path/config/vproxy_cred ] 
then
	echo "initiating openvpn connection ..." >> $allproxy_path/log/vproxy
	openvpn --config $vproxy_path --writepid $allproxy_path/pid/vproxy --auth-user-pass $(pwd)$vpnbook_cred_path \
		--http-proxy-timeout 5 --http-proxy $vproxy_server $vproxy_port $(pwd)$vproxy_cred_path basic \
		> $allproxy_path/log/openvpn 2>&1 & 
	sleep 0.5
	echo "removing temporary credential files ..." >> $allproxy_path/log/vproxy
	sudo rm -rf $(pwd)$vproxy_cred_path $(pwd)$vpnbook_cred_path 2>&1 & 
	echo "credential files removed" >> $allproxy_path/log/vproxy
	echo -n "Waiting for openvpn connection ..." >> $allproxy_path/log/vproxy

else
	echo "config files not found" >> $allproxy_path/log/vproxy
	echo "Exit On Error !" >> $allproxy_path/log/vproxy
fi
