#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi
# echo "This is the easy version of starting up the transparent proxy."
# echo "The backend needs to compiled. I've done that in the script itself."
# echo "In case make fails, you will need to compile libevent. I've included the tar for it. Extract it and use the readme file. "

case $1 in
tproxy)
	source ./tproxy/start.sh &
;;
vproxy)
	source ./vproxy/start.sh &
;;
lproxy)
	source ./lproxy/start.sh &
;;
sproxy)
	source ./sproxy/start.sh &
;;
*)
	echo "Removing log files ..."
	sudo rm -rf *.log log/*.log #&
	echo "Log files removed"

	echo "Stopping process if already running ..."
	. ./stop.sh > ./log/stop.log

	echo "Checking connectivity to default Gateway ..."
	def_dns=$(/sbin/ip route | awk '/default/ { print $3 }')
	if [[ ! $def_dns =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
	then
		echo "default gateway not set"
		read -p "Proxy Gateway ? : " proxy_gateway
		if  [[ $proxy_gateway =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
		then
			ping -W 1 -c 2 $proxy_gateway >/dev/null
			ping -W 1 -c 2 $proxy_gateway >/dev/null
			if [ $? -eq 0 ]
			then
				echo "Internet is up."
				sudo ip route add default via $proxy_gateway
			else
				echo "Offline"
				echo "Check Internet Access and try again"
				echo "Exit on Error !"
				exit
			fi
		else
			echo "incorrect gateway"
			read -p "Proxy Gateway ? : " proxy_gateway
		fi
	else
		ping -W 1 -c 2 $def_dns >/dev/null
		ping -W 1 -c 2 $def_dns >/dev/null
		if [ $? -eq 0 ]
		then
			echo "Internet is up."
		else
			echo "Offline"
			read -p "Proxy Server Gateway ? : " proxy_gateway
			if  [[ $proxy_gateway =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]
			then
				ping -W 1 -c 2 $proxy_gateway >/dev/null
				ping -W 1 -c 2 $proxy_gateway >/dev/null
				if [ $? -eq 0 ]
				then
					echo "Internet is up."
					# sudo ip route add default via $proxy_gateway
				else
					echo "Offline"
					echo "Check Internet Access and try again"
					echo "Exit on Error !"
					exit
				fi
			fi
		fi
	fi


	req_packages=( "libevent-dev" "openvpn" "plasma-nm" "libnet-proxy-perl" "putty" "squid3" )
	for i in "${req_packages[@]}"
	do
		PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $i |grep "installed")
		echo Checking package $i: $PKG_OK
		if [ "" = "$PKG_OK" ]; then
		  echo "No $i. Setting up $i."
		  sudo apt-get --force-yes --yes install $i
		fi
	done

	if [ ! -f ./config/config.sh ] 
	then
		echo "Creating file config.sh ..."
		touch ./config/config.sh
		cp ./config/config_bak.sh ./config/config.sh
	else
		echo -n "read from config file ?[y/n] : "
		read -p "" choice
	fi

	chmod +rwx ./config/config.sh

	vpnbook_cred_path="/config/vpnbook_cred"
	proxy_cred_path="/config/proxy_cred"

	if [ "$choice" = "y" ]
	then
	    source ./config/config.sh
	else
		read -p "Proxy address ? : " proxy_server
		read -p "Proxy port ? : " proxy_port
		read -p "Proxy username ? : " proxy_username
		stty -echo
		read -p "Proxy password ? : " proxy_password; echo 
		stty echo
		read -p "Proxy Gateway ? : " proxy_gateway
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
			echo "export proxy_server=$proxy_server " > ./config/config.sh
			echo "export proxy_port=$proxy_port " >> ./config/config.sh
			echo "export proxy_username=$proxy_username " >> ./config/config.sh
			echo "export proxy_password=$proxy_password " >> ./config/config.sh
			echo "export proxy_gateway=$proxy_gateway " >> ./config/config.sh
			echo "export vpnbook_username=$vpnbook_username " >> ./config/config.sh
			echo "export vpnbook_password=$vpnbook_password " >> ./config/config.sh
			echo "export vpnbook_path=$vpnbook_path " >> ./config/config.sh
			echo "export restore_dns=$(/sbin/ip route | awk '/default/ { print $3 }')" >> ./config/config.sh
			echo "" >> ./config/config.sh
		fi
	fi

;;

esac
