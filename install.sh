#!/bin/bash

# run with sudo rights only
if [ "$EUID" -ne 0 ]
  then echo "Please run with sudo "
  exit
fi

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# run only inside Allproxy folder
if [ ! -f "Allproxy.pro" ];then
	echo "Please run in Allproxy folder"
	exit 1
fi

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

# update
sudo -E apt-get update

# install required packages
req_packages=( "libevent-dev" "openvpn" "libnet-proxy-perl" "qt5-qmake" "netmask" \
	"putty" "sshpass" "netcat" "openssh-server" "notify-osd" "privoxy" \
	"openssh-client" "gksu" "python-pycurl" "zenity" "redsocks" "qt5-default" \
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

# set allproxy path
cur_path=$(pwd)
log_name=$(logname)

sed -i 's|allproxy_path=.*|allproxy_path='"$cur_path"'|g' config/config.sh
echo "export allproxy_path=$cur_path" >> /home/$logname/.bashrc
echo "export allproxy_path=$cur_path" >> /etc/environment

echo ". $cur_path/config/config.sh" >> /home/$logname/.bashrc

#############################
## create log/config files ##
#############################

mkdir log/
touch config/libnet-proxy-perl log/config_routes log/cproxy log/dns log/fproxy log/openvpn log/redsocks \
	log/sproxy log/start.log log/stop.log log/tproxy log/unconfig_routes log/vproxy


############
## nproxy ##
############

user=$(logname)

# backup files 
back_files=( "$HOME/.bashrc" )
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

# add sbin to path
PATH="$PATH:/usr/sbin"

# restart network manager 
sudo service network-manager restart