#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source ./config/config.sh

echo "Sproxy" > ./log/sproxy
echo "$sproxy_local_port" >> ./log/sproxy
echo "$sproxy_server" >> ./log/sproxy
echo "$sproxy_port" >> ./log/sproxy
echo "$sproxy_username" >> ./log/sproxy
echo "$sproxy_ssh_server" >> ./log/sproxy
echo "$sproxy_password" >> ./log/sproxy

echo "Creating SSH Tunnel ..." >> ./log/sproxy
sshpass -p $sproxy_password ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -f -N -L $sproxy_local_port:$sproxy_server:$sproxy_port $sproxy_username@$sproxy_ssh_server  >/dev/null 2>&1
echo "Tunnel created" >> ./log/sproxy

sleep 5

echo "Getting pid" >> ./log/sproxy
echo `ps aux | grep -m 1 -F 'ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -f -N -L' | grep -v -F 'sshpass' | grep -v -F 'grep' | awk '{ print $2 }'` > ./pid/sproxy
echo "got pid" >> ./log/sproxy