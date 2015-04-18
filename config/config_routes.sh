#!/bin/bash
source /etc/environment

source $allproxy_path/config/config.sh #&

def_gate=$(/sbin/ip route | awk '/default/ { print $3 }')
# echo $def_gate

if [[ $def_gate =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] 
then
	ping -W 1 -c 2 $def_gate >/dev/null
	ping -W 1 -c 2 $def_gate >/dev/null
	if [ $? -eq 0 ]
	then
		echo "Internet is up."

	else
		echo "Offline"
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
			fi

		fi
		read -p "Proxy Server Gateway ? : " def_gate
		if  [[ $def_gate =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]
		then
			ping -W 1 -c 2 $def_gate >/dev/null
			ping -W 1 -c 2 $def_gate >/dev/null
			if [ $? -eq 0 ]
			then
				echo "Internet is up."
				# sudo ip route add default via $def_gate
			else
				echo "Offline"
				echo "Check Internet Access and try again"
				echo "Exit on Error !"
				exit
			fi
		fi
	fi
fi
