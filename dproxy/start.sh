#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/environment
source $allproxy_path/config/config.sh

python $allproxy_path/dproxy/main.py $1 $2 & # -p "http://$nproxy_username:$nproxy_password@nproxy_server:$nproxy_port" &

echo $! > $allproxy_path/pid/dproxy #&
