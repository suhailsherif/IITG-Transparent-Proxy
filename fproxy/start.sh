#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/environment
source /home/$(logname)/.bashrc

source $allproxy_path/config/config.sh

echo "Fproxy " > $allproxy_path/log/fproxy

exec ncat -l -k 12121 > $allproxy_path/fproxy/cmdin &  

echo `ps aux | grep -m 1 -F 'ncat -l -k 12121' | grep -v -F 'grep' | awk '{ print $2 }'` > $allproxy_path/pid/fproxy

sleep 1
source $allproxy_path/fproxy/daemon.sh &
echo $! > $allproxy_path/pid/fproxy_daemon	 #&