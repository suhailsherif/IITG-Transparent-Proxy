#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/environment
source /home/$(logname)/.bashrc

source $allproxy_path/config/config.sh

echo "Cproxy " > $allproxy_path/log/cproxy

exec ncat -l -k 13131 > $allproxy_path/cproxy/cmdin &  

echo `ps aux | grep -m 1 -F 'ncat -l -k 13131' | grep -v -F 'grep' | awk '{ print $2 }'` > $allproxy_path/pid/cproxy

sleep 1
source $allproxy_path/cproxy/daemon.sh &
echo $! > $allproxy_path/pid/c
proxy_daemon	 #&