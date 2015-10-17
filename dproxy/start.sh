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

python $allproxy_path/dproxy/main.py $1 $2 $allproxy_path/dproxy & # -p "http://$nproxy_username:$nproxy_password@nproxy_server:$nproxy_port" &

echo $! > $allproxy_path/pid/dproxy #&
