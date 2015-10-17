#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

log_name=$(logname)

if [ $log_name = "no login name" ]; then
	log_name=$(id -nu)
else
	if [ $log_name = "root" ]; then
		log_name=$(ps -o user= -p $$ | awk '{print $1}')
	fi
fi

source /etc/environment
source /home/$log_name/.bashrc

source $allproxy_path/config/config.sh

echo "Cproxy " > $allproxy_path/log/cproxy

cp "$allproxy_path/cproxy/server.conf.in" "$allproxy_path/cproxy/server.conf"
sed -i s/cproxy_ip/$1/g $allproxy_path/cproxy/server.conf
sed -i s/cproxy_port/$2/g $allproxy_path/cproxy/server.conf

MACHINE_TYPE=`uname -m`

if [ ${MACHINE_TYPE} == 'x86_64' ]; then
	# 64 bit
	$allproxy_path/cproxy/bin/linux_amd64 $allproxy_path/cproxy/server.conf &
else
	# 32 bit
	$allproxy_path/cproxy/bin/linux_386 $allproxy_path/cproxy/server.conf &
fi

echo "Opening link http://$1:$2"
xdg-open "http://$1:$2"

# exit
