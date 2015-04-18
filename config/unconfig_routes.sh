#!/bin/bash
source /etc/environment
source $allproxy_path/config/config.sh

sudo ip route del 202.141.80.0/23 via $nproxy_gateway

def_gateway=$(/sbin/ip route | awk '/default/ { print $3 }')

if [[ $def_gate =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
then
	ping -W 1 -c 2 $def_gate >/dev/null
	ping -W 1 -c 2 $def_gate >/dev/null
	if [ $? -eq 0 ]
	then
		echo "Internet is up."
		exit

	else
		if [ -e /usr/bin/zenity ]; then		

			OUTPUT=$(zenity --forms --title="Allproxy" --text="Proxy Settings" --separator=","  \
			   --add-entry="Proxy Gateway" )

			accepted=$?
			if [ ! "$accepted" -eq "0" ]; then
				echo "Tproxy aborted !!"
			    exit 1
			else
				tproxy_gateway=$(echo $OUTPUT | awk -F, '{print $1}')

				sudo ip route del default

				echo "setting default gateway to " $tproxy_gateway
				sudo ip route add default via $tproxy_gateway
				exit
			fi

		fi
		
	fi
fi
