#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

req_packages=( "libevent-dev" "openvpn" "plasma-nm" "libnet-proxy-perl"\
	"putty" "squid3" "sshpass" "netcat" "openssh-server" "openssh-sftp-server" "openssh-client" "gksu" )
for i in "${req_packages[@]}"
do
	PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $i |grep "installed")
	echo Checking package $i: $PKG_OK
	if [ "" = "$PKG_OK" ]; then
	  echo "No $i. Setting up $i."
	  sudo apt-get --force-yes --yes install $i
	fi
done

user=$(logname)

back_files=( "/etc/environment" "/home/$user/.bashrc" )
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

if [ ! -f ./config/config.sh ] 
then
	echo "Creating file config.sh ..."
	cp ./config/config_bak.sh ./config/config.sh
fi


echo $http_proxy | grep -P -o "[a-z]+.?[a-z]*:[^\/\\:;@]+@[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}:[0-9]{1,4}" | awk -F '[/:@]' \
	'{http_server=$1;http_port=$2;http_username=$3;http_password=$4;}'
echo $http_username