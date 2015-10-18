#!/bin/bash

# run inside tproxy folder
cd "$(dirname "$0")"

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/allproxy/config
source $allproxy_path/config/config.sh

. $allproxy_path/tproxy/script stop

if pgrep "redsocks" > /dev/null
then
    sudo killall redsocks
fi

if pgrep "dnsmasq" > /dev/null
then
    sudo killall dnsmasq
fi

# sudo ps -ef | grep "redsocks" | awk '{print $2}' | xargs kill

if [ -f $allproxy_path/pid/tproxy ] 
then 
	typeset -i pid=$(cat $allproxy_path/pid/tproxy)
	sudo kill -15 $pid
fi

echo "Transparent proxy stopped."
exit
