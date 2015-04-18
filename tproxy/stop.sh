#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment
source $allproxy_path/config/config.sh

. $allproxy_path/tproxy/script stop
sudo killall redsocks
# sudo killall dnsmasq

# sudo ps -ef | grep "redsocks" | awk '{print $2}' | xargs kill

if [ -f $allproxy_path/pid/tproxy ] 
then 
	typeset -i pid=$(cat $allproxy_path/pid/tproxy)
	kill -15 $pid
fi
