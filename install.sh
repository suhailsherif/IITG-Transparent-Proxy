#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# check internet connection
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

		proxy_server=$(echo $OUTPUT | awk -F, '{print $1}')
		proxy_port=$(echo $OUTPUT | awk -F, '{print $2}')
		proxy_username=$(echo $OUTPUT | awk -F, '{print $3}')
		proxy_password=$(echo $OUTPUT | awk -F, '{print $4}')
		

		export http_proxy="http://$proxy_username:$proxy_password@$proxy_server:$proxy_port/"
		export https_proxy="https://$proxy_username:$proxy_password@$proxy_server:$proxy_port/"
		
		status_code=$(curl -sL -w "%{http_code}\\n" "http://www.google.co.in/" -o /dev/null)
		if [ "$status_code" = "200" ];then
			echo "Proxy Connection successful"
		else
			echo "Proxy Connection failed"
			echo "Installation aborted . Try reinstalling"
			exit
		fi
	fi
fi

# update
sudo -S apt-get update && sudo apt-get upgrade -y

# install required packages
req_packages=( "libevent-dev" "openvpn" "plasma-nm" "libnet-proxy-perl" "dnsmasq" \
	"putty" "squid3" "sshpass" "netcat" "openssh-server" "nmap" "notify-osd" \
	"openssh-client" "gksu" "python-pycurl" "opus-tools" "zenity" "redsocks" \
	)
for i in "${req_packages[@]}"
do
	PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $i |grep "installed")
	echo Checking package $i: $PKG_OK
	if [ "" = "$PKG_OK" ]; then
	  echo "$i not installed, setting up $i ..."
	  sudo apt-get --force-yes --yes install $i
	fi
done

# create the configuration file
if [ ! -f ./config/config.sh ] 
then
	echo "Creating file config.sh ..."
	cp ./config/config_bak.sh ./config/config.sh
fi

# set allproxy path
cur_path=$(pwd)
sed -i 's|allproxy_path=.*|allproxy_path='"$cur_path"'|g' config/config.sh
echo "export allproxy_path=$cur_path" >> $HOME/.bashrc
echo "allproxy_path=$cur_path" >> /etc/environment

echo ". $allproxy_path/config/config.sh" >> $HOME/.bashrc

############
## nproxy ##
############
user=$(logname)
# backup files 
back_files=( "/etc/environment" "/etc/apt/apt.conf" "$HOME/.bashrc" )
for i in "${back_files[@]}"
do
	if [ -e "$i" ] 
	then
		echo "backing up $i"
		sudo cp $i $i"_ibak"
	else
		echo "could not find $i"
	fi
done

echo $http_proxy | grep -P -o "[a-z]+.?[a-z]*:[^\/\\:;@]+@[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}:[0-9]{1,4}" | awk -F '[/:@]' \
	'{http_server=$1;http_port=$2;http_username=$3;http_password=$4;}'
echo $http_username

############
## tproxy ##
############

chown root:root -R /var/log
chmod 777 -R /var/log


############
## dproxy ##
############

# set python version
python_version=2.7

# Make the main file executable
chmod a+x ./dproxy/main.py

# Copy the downloader class library to /usr/lib/python (this can be changed based on the version of python)
cp ./dproxy/downloader.py /usr/lib/python$python_version/

# Copy the main file to the bin folder
cp ./dproxy/main.py /usr/bin/pycurl-download

# Create a log file and change its read write permission
touch /var/log/downloader.log ; chmod 777 /var/log/downloader.log


############
## cproxy ##
############

# install desktop notifier
sudo -E add-apt-repository ppa:leolik/leolik -y
sudo -E add-apt-repository ppa:amandeepgrewal/notifyosdconfig -y
sudo -S apt-get update && sudo apt-get upgrade -y
sudo apt-get install notifyosdconfig libnotify-bin
notifyosdconf 

######################
## add sbin to path ##
######################

PATH="$PATH:/usr/sbin"

######################
## turn off dnsmasq ##
######################

sudo cat /etc/NetworkManager/NetworkManager.conf \
    | sed -e 's/dns=dnsmasq/#dns=dnsmasq/' \
    > /etc/NetworkManager/NetworkManager.conf

#############################
## restart network manager ##
#############################
sudo service network-manager restart