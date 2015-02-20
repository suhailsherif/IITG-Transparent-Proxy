#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }


sshpass -p $ssh_pass ssh  -f -N -L $ssh_local_port:$ssh_proxy_server:$ssh_proxy_port $ssh_username@$ssh_server
echo `ps aux | grep -F 'ssh -f -N -L' | grep -v -F 'grep' | awk '{ print $2 }'` > ./pid/sproxy