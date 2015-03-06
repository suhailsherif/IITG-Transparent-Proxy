#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment

sudo ps -ef | grep "squid3" | awk '{print $2}' | xargs kill

echo "7" >> new.txt

sudo echo "8" >> new.txt
if [ -f $allproxy_path/pid/lproxy ] 
then 
	sed 's|[0-9]*|sudo kill &|g' $allproxy_path/pid/lproxy | bash
	rm $allproxy_path/pid/lproxy
	
fi

if [ -f /etc/squid3/squid_bak.conf ] 
then 
	sudo mv /etc/squid3/squid_bak.conf /etc/squid3/squid.conf 
fi