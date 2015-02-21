#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

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
nproxy)
	
	source ./nproxy/start.sh &
;;
*)
	echo "Stopping process if already running ..."
	. ./stop.sh > ./log/stop.log

	echo "Checking connectivity to default Gateway ..."
	def_gateway=$(/sbin/ip route | awk '/default/ { print $3 }')
	if [[ ! $def_gateway =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
	then
		echo "default gateway not set"
		read -p "Proxy Gateway ? : " def_gateway
		if  [[ $proxy_gateway =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
		then
			ping -W 1 -c 2 $proxy_gateway >/dev/null
			ping -W 1 -c 2 $proxy_gateway >/dev/null
			if [ $? -eq 0 ]
			then
				echo "Internet is up."
				sudo ip route add default via $def_gateway
			else
				echo "Offline"
				echo "Check Internet Access and try again"
				echo "Exit on Error !"
				exit
			fi
		else
			echo "incorrect gateway"
			read -p "Proxy Gateway ? : " def_gateway
		fi
	else
		ping -W 1 -c 2 $def_gateway >/dev/null
		ping -W 1 -c 2 $def_gateway >/dev/null
		if [ $? -eq 0 ]
		then
			echo "Internet is up."
		else
			echo "Offline"
			read -p "Proxy Server Gateway ? : " def_gateway
			if  [[ $def_gateway =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]
			then
				ping -W 1 -c 2 $def_gateway >/dev/null
				ping -W 1 -c 2 $def_gateway >/dev/null
				if [ $? -eq 0 ]
				then
					echo "Internet is up."
					# sudo ip route add default via $def_gateway
				else
					echo "Offline"
					echo "Check Internet Access and try again"
					echo "Exit on Error !"
					exit
				fi
			fi
		fi
	fi

	sed -i s/restore_gateway=.*/restore_gateway=$def_gateway/g config/config.sh

	req_packages=( "libevent-dev" "openvpn" "plasma-nm" "libnet-proxy-perl" "putty" "squid3" "sshpass" )
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
	fi

	echo "Check your config/config.sh file"
	read -p "Press [Enter] key to start ..."

	chmod +rwx ./config/config.sh

	source ./config/config.sh

	read -p "Which proxy ? : " which_proxy

	case $which_proxy in
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
	nproxy)
		source ./nproxy/start.sh &
	;;
	esac
;;

esac
