#!/bin/bash

## force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

## run only inside Allproxy folder
cd "$(dirname "$0")"

sudo echo "Installing Allproxy."

## install curl
sudo apt-get install curl

command -v curl >/dev/null 2>&1 || { echo >&2 "\"curl\" required but it's not installed.  Aborting."; exit 1; }

## check internet connection
status_code=$(curl -sL -w "%{http_code}\\n" "http://www.google.co.in/" -o /dev/null)
if [ "$status_code" = "200" ];then
	echo "Proxy Connection successful"
else
	if [ -e /usr/bin/zenity ]; then

		OUTPUT=$(zenity --forms --title="Allproxy" --text="Proxy Settings" --separator=","  \
		   --add-entry="Proxy Server" \
		   --add-entry="Proxy Port" \
		   --add-entry="Username" \
		   --add-password="Password" )

		accepted=$?
		if [ ! "$accepted" -eq "0" ]; then
			echo "Installation aborted !!"
		    exit 1
		fi

		# extract proxy parameters from zenity output
		proxy_server=$(echo $OUTPUT | awk -F, '{print $1}')
		proxy_port=$(echo $OUTPUT | awk -F, '{print $2}')
		proxy_username=$(echo $OUTPUT | awk -F, '{print $3}')
		proxy_password=$(echo $OUTPUT | awk -F, '{print $4}')
		

	else 
		read "Proxy server : " proxy_server
		read "Proxy port : " proxy_port
		read "Proxy username : " proxy_username
		read -s -p "Proxy password : " proxy_password
	fi

	if [[ $proxy_server =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]] && [[ $proxy_port =~ ^[0-9]{1,5}$ ]]; then

		# set proxy for this session
		export http_proxy="http://$proxy_username:$proxy_password@$proxy_server:$proxy_port/"
		export https_proxy="https://$proxy_username:$proxy_password@$proxy_server:$proxy_port/"
		
		# check again if proxy connection successful
		status_code=$(curl -sL -w "%{http_code}\\n" "http://www.google.co.in/" -o /dev/null)
		if [ "$status_code" = "200" ];then
			echo "Proxy Connection successful"
		else
			echo "Proxy Connection failed"
			echo "Installation aborted . Try reinstalling"
			exit
		fi
	else
		echo "Invalid proxy. Aborting."
		exit
	fi
fi

## update
sudo -E apt-get update

## install required packages
req_packages=( "libevent-dev" "openvpn" "qt5-qmake" "qt5-default" "netmask" \
	"putty" "sshpass" "openssh-server" "openssh-client" "privoxy" "g++" "curl" \
	"gksu" "python-pycurl" "zenity" "redsocks" "netcat" \
	)
for i in "${req_packages[@]}"
do
	sudo -E apt-get --force-yes --yes install $i
done

# compile Allproxy
qmake Allproxy.pro
make

# create the configuration file
if [ ! -f ./config/config.sh ] 
then
	echo "Creating file config.sh ..."
	if [ ! -f ./config/config_bak.sh ]
	then
		echo "Could not find initial config file. Aborting."
		exit
	fi
	cp ./config/config_bak.sh ./config/config.sh
fi

#############################
## create log/config files ##
#############################

## user-specific directory
if [ ! -d $HOME/.allproxy ]; then
	mkdir $HOME/.allproxy
fi

touch $HOME/.allproxy/config

## global directory
if [ ! -d /etc/allproxy ]; then
	sudo mkdir -p /etc/allproxy
fi

sudo touch /etc/allproxy/config

## set allproxy path
cur_path=$(pwd)

sed -i 's|allproxy_path=.*|allproxy_path='"$cur_path"'|g' config/config.sh
echo "export allproxy_path=$cur_path" >> $HOME/.allproxy/config
echo "export allproxy_path=$cur_path" | sudo tee -a /etc/allproxy/config > /dev/null

# echo ". $cur_path/config/config.sh" >> $HOME/.bashrc

if [ ! -d log ]; then
	mkdir log/
fi

touch log/config_routes log/cproxy log/dns log/fproxy log/openvpn log/redsocks \
	log/sproxy log/start.log log/stop.log log/tproxy log/unconfig_routes log/vproxy \
	tproxy/dnsCache


## enable dash launching
cp allproxy.desktop.in allproxy.desktop
sed -i 's|allproxy_path|'"$cur_path"'|g' allproxy.desktop
chmod +x allproxy.desktop

if [ -d /usr/share/applications ]; then
	sudo cp allproxy.desktop /usr/share/applications/allproxy.desktop
fi

############
## nproxy ##
############


# backup files 
back_files=( "$HOME/.bashrc" "/etc/environment" )
for i in "${back_files[@]}"
do
	if [ -e "$i" ] 
	then
		if [ ! -f $i"_allproxy_bak" ]; then
			echo "backing up $i"
			sudo cp $i $i"_allproxy_bak"
		fi
	else
		echo "could not find $i"
	fi
done

############
## tproxy ##
############

sudo chown root:root -R /var/log
sudo chmod 777 -R /var/log

# turn off automatic dnsmasq
if [ -f /etc/NetworkManager/NetworkManager.conf ]; then
	sudo sed -i "s/dns=dnsmasq/# dns=dnsmasq/g" /etc/NetworkManager/NetworkManager.conf
fi

############
## dproxy ##
############

## Make the main file executable
chmod a+x ./dproxy/main.py
syst
## Create a log file and change its read write permission
sudo touch /var/log/downloader.log
sudo chmod 777 /var/log/downloader.log

## restart network manager 
sudo service network-manager restart