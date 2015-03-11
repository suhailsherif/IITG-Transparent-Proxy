#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/environment
source $allproxy_path/config/config.sh

IP=$(ifconfig | grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1' | grep -m 1 -Eo '([0-9]*\.){3}[0-9]*')

msg="$IP#request#$fproxy_upload_type#$(basename $fproxy_upload_path)#$(date "+%s")#"
echo $msg >> $allproxy_path/log/cproxy
echo "----------------------------" >> $allproxy_path/log/cproxy
echo $msg | ncat $fproxy_dest_ip 13131