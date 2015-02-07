#!/bin/bash

sudo echo "This is the easy version of starting up the transparent proxy."
echo "The backend needs to compiled. I've done that in the script itself."
echo "In case make fails, you will need to compile libevent. I've included the tar for it. Extract it and use the readme file. "

sudo fuser -k 55/udp
sleep 0.1

if [ ! -f ./redsocks/redsocks ] 
then
	make -C ./redsocks/
fi

if [ ! -f ./config.sh ] 
then
	touch config.sh
	cp config_bak.sh config.sh
fi

chmod +rwx config.sh

vpnbook_cred_path="/vpnbook_cred"
proxy_cred_path="/proxy_cred"

echo -n "read from config file ?[y/n] : "
read -p "" choice

if [ "$choice" = "y" ]
then
    while read line; do    
        eval $line    
    done < ./config.sh
else
	read -p "Proxy address ? : " proxy_server
	read -p "Proxy port ? : " proxy_port
	read -p "Proxy username ? : " proxy_username
	stty -echo
	read -p "Proxy password ? : " proxy_password; echo 
	stty echo
	read -p "VPNBook username ? : " vpnbook_username
	read -p "VPNBook password ? : " vpnbook_password
	read -p "VPN config file path(full) ? : " vpnbook_path
	echo -n "\nDo you want to save your configuration ?[y/n] : "
	read -p "" save
	if [ "$save" = "y" ]
	then
		echo "export proxy_server=$proxy_server " > config.sh
		echo "export proxy_port=$proxy_port " >> config.sh
		echo "export proxy_username=$proxy_username " >> config.sh
		echo "export proxy_password=$proxy_password " >> config.sh
		echo "export vpnbook_username=$vpnbook_username " >> config.sh
		echo "export vpnbook_password=$vpnbook_password " >> config.sh
		echo "export vpnbook_path=$vpnbook_path " >> config.sh
		echo "" >> config.sh
	fi
fi

echo "$vpnbook_username\n$vpnbook_password" > $(pwd)$vpnbook_cred_path
echo "$proxy_username\n$proxy_password" > $(pwd)$proxy_cred_path


./script start & 
./redsocksConfig.sh $proxy_server $proxy_port $proxy_username $proxy_password & 
sudo python fakeDNS.py &
echo $! > pidfile.temp &
if [ -f ./vpnbook_cred ] && [ -f ./proxy_cred ] 
then
	openvpn --config $vpnbook_path --auth-user-pass $(pwd)$vpnbook_cred_path --http-proxy $proxy_server $proxy_port $(pwd)$proxy_cred_path basic &
	sleep 0.1
	sudo rm -rf ./proxy_cred ./vpnbook_cred &
else
	echo "config files not found"
	echo "\n\nExit On Error !\n\n"
fi




