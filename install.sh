#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# install required packages
req_packages=( "libevent-dev" "openvpn" "plasma-nm" "libnet-proxy-perl"\
	"putty" "squid3" "sshpass" "netcat" "openssh-server" \
	"openssh-client" "gksu" "python-pycurl" "opus-tools" "zenity" )
for i in "${req_packages[@]}"
do
	PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $i |grep "installed")
	echo Checking package $i: $PKG_OK
	if [ "" = "$PKG_OK" ]; then
	  echo "No $i. Setting up $i."
	  sudo apt-get --force-yes --yes install $i
	fi
done

# create a config file
if [ ! -f ./config/config.sh ] 
then
	echo "Creating file config.sh ..."
	cp ./config/config_bak.sh ./config/config.sh
fi

# set allproxy path
cur_path=$(pwd)
sed -i 's|allproxy_path=.*|allproxy_path='"$cur_path"'|g' config/config.sh
echo "export allproxy_path=$cur_path" >> ~/.bashrc
echo "allproxy_path=$cur_path" >> /etc/environment

echo ". $allproxy_path/config/config.sh" >> ~/.bashrc

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

# make redsocks
if [ ! -f ./redsocks/redsocks ] 
then
	echo "making redsocks"
	make -C ./redsocks/ 
fi


############
## dproxy ##
############
python_version=2.7

# Make the main file executable
chmod a+x ./dproxy/main.py

# Copy the downloader class library to /usr/lib/python (this can be changed based on the version of python)
cp ./dproxy/downloader.py /usr/lib/python$python_version/

# Copy the main file to the bin folder
cp ./dproxy/main.py /usr/bin/pycurl-download

# Create a log file and change its read write permission
touch /var/log/downloader.log ; chmod 777 /var/log/downloader.log
