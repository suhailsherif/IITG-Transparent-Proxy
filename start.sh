#!/bin/bash

if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi
echo "This is the easy version of starting up the transparent proxy."
echo "The backend needs to compiled. I've done that in the script itself."
echo "In case make fails, you will need to compile libevent. I've included the tar for it. Extract it and use the readme file. "

echo "Removing log files ..."
sudo rm -rf *.log log/*.log &
echo "Log files removed"

echo "Stopping process if already running ..."
sudo ./stop.sh > ./log/stop.log

echo "Checking Internet connection ..."
if ping -W 5 -c 1 202.141.80.3 >/dev/null; then
    echo "Internet is up."
else
    echo "Offline"
    echo "Check Internet Access and try again"
    echo "Exit on Error !"
    exit
fi

req_packages=( "libevent-dev" "openvpn" "plasma-nm" )

for i in "${req_packages[@]}"
do
	PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $i |grep "installed")
	echo Checking package $i: $PKG_OK
	if [ "" = "$PKG_OK" ]; then
	  echo "No $i. Setting up $i."
	  sudo apt-get --force-yes --yes install $i
	fi
done

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

if [ ! -f ./config.sh ] 
then
	echo "Creating file config.sh ..."
	touch config.sh
	cp config_bak.sh config.sh
else
	echo -n "read from config file ?[y/n] : "
	read -p "" choice
fi

chmod +rwx config.sh

vpnbook_cred_path="/vpnbook_cred"
proxy_cred_path="/proxy_cred"

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
	for f in ./*.ovpn; do
	    echo -n "Do you want to use $f as server configuration file ?[y/n] : "
	    read -p "" ch
	    if [ "$ch" = "y" ] ;then
	    	vpnbook_path=$(readlink -f $f)
			break
		fi
	done
	if [ ! -z "$vpnbook_path" ]; then 
		read -p "VPN config file path(full) ? : " vpnbook_path
	fi
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

echo "Creating temporary files for openvpn connection ..."
echo "$vpnbook_username" > $(pwd)$vpnbook_cred_path
echo "$vpnbook_password" >> $(pwd)$vpnbook_cred_path

echo "$proxy_username" > $(pwd)$proxy_cred_path
echo "$proxy_password" >> $(pwd)$proxy_cred_path


./script start & 
echo "Configuring redsocks ..."
./redsocksConfig.sh $proxy_server $proxy_port $proxy_username $proxy_password > ./log/Redsocks.log 2>&1 & 
echo "redsocks configured successfully"
echo "initiating fake DNS server ..."
sudo python -u fakeDNS.py > ./log/DNS.log & 
echo "DNS server initiated"
echo $! > pidfile.temp &
if [ -f ./vpnbook_cred ] && [ -f ./proxy_cred ] 
then
	echo "initiating openvpn connection ..."
	openvpn --config $vpnbook_path --auth-user-pass $(pwd)$vpnbook_cred_path --http-proxy $proxy_server $proxy_port $(pwd)$proxy_cred_path basic > ./log/openvpn.log &
	sleep 0.5
	echo "removing temporary credential files ..."
	sudo rm -rf ./proxy_cred ./vpnbook_cred &
	echo "credential files removed"
	echo -n "Waiting for openvpn connection ..."
	while ! grep -q "Initialization Sequence Completed" "./log/openvpn.log"; do
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

echo "Transparent proxy initiated, running in background"
echo "Exit on success !"