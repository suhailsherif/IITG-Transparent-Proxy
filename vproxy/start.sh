#!/bin/bash

echo "Creating temporary files for openvpn connection ..."
echo "$vpnbook_username" > $(pwd)$vpnbook_cred_path
echo "$vpnbook_password" >> $(pwd)$vpnbook_cred_path

echo "$proxy_username" > $(pwd)$proxy_cred_path
echo "$proxy_password" >> $(pwd)$proxy_cred_path

if [ -f ./config/vpnbook_cred ] && [ -f ./config/proxy_cred ] 
then
	echo "initiating openvpn connection ..."
	openvpn --config $vpnbook_path --auth-user-pass $(pwd)$vpnbook_cred_path --http-proxy-timeout 5 \
		--http-proxy $proxy_server $proxy_port $(pwd)$proxy_cred_path basic > ./log/openvpn.log &
	sleep 0.5
	echo `ps aux | grep -F 'openvpn' | grep -v -F 'grep' | awk '{ print $2 }'` > ./pid/vproxy
	echo "removing temporary credential files ..."
	sudo rm -rf $(pwd)$proxy_cred_path $(pwd)$vpnbook_cred_path &
	echo "credential files removed"
	echo -n "Waiting for openvpn connection ..."
	while ! tac "./log/openvpn.log" | grep -q "Initialization Sequence Completed" ; do
		if tac "./log/openvpn.log" | grep -q "HTTP/1.0 403 Forbidden" 
		then
			echo ""
			echo "403 Forbidden Error"
			echo "Check config.sh and try again"
			echo "Exit on error !"
			exit
		fi		
		if tac "./log/openvpn.log" | grep -q "process exiting" 
		then
			echo ""
			echo "Openvpn Connection Error"
			echo "Check config.sh and try again"
			echo "Exit on error !"
			exit
		fi		

		echo -n "."
		sleep 1
		echo -n " ."
		sleep 0.5
	done
	echo ""
	echo "Openvpn connection successful"
else
	echo "config files not found"
	echo "Exit On Error !"
fi
