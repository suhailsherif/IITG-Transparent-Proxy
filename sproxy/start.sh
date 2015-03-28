#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment

source $allproxy_path/config/config.sh

echo "Sproxy" > $allproxy_path/log/sproxy
echo "$sproxy_local_port" >> $allproxy_path/log/sproxy
echo "$sproxy_server" >> $allproxy_path/log/sproxy
echo "$sproxy_port" >> $allproxy_path/log/sproxy
# echo "$sproxy_username" >> $allproxy_path/log/sproxy
echo "$sproxy_ssh_server" >> $allproxy_path/log/sproxy
# echo "$sproxy_password" >> $allproxy_path/log/sproxy

echo "Creating SSH Tunnel ..." >> $allproxy_path/log/sproxy
sshpass -p $sproxy_password ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -f -N -L $sproxy_local_port:$sproxy_server:$sproxy_port $sproxy_username@$sproxy_ssh_server  >/dev/null 2>&1 &

sleep 5

echo "Tunnel created" >> $allproxy_path/log/sproxy
echo "Getting pid" >> $allproxy_path/log/sproxy
echo `ps aux | grep -m 1 -F 'ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -f -N -L' | grep -v -F 'sshpass' | grep -v -F 'grep' | awk '{ print $2 }'` > $allproxy_path/pid/sproxy
echo "got pid" >> $allproxy_path/log/sproxy