#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment

sudo fuser -k 55/udp
. $allproxy_path/config/script stop
sudo killall redsocks

# sudo ps -ef | grep "redsocks" | awk '{print $2}' | xargs kill

if [ -f $allproxy_path/pid/tproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' $allproxy_path/pid/tproxy | bash
	rm $allproxy_path/pid/tproxy
fi
