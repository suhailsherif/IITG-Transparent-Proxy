#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

# echo "Fproxy " > $allproxy_path/log/fproxy
echo "ok"
nc -l -k 12121 > $allproxy_path/fproxy/cmdin &  
# . fproxy/daemon.sh &
echo `ps aux | grep -m 1 -F 'nc -l -k 12121' | grep -v -F 'grep' | awk '{ print $2 }'` > $allproxy_path/pid/fproxy
echo "not ok"