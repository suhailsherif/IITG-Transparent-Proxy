#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

echo "This script stops the transparent proxy and restores the normal behavior"
if [ -f pidfile.temp ] 
then 
	sed 's|[0-9]*|sudo kill &|g' pidfile.temp | bash
	rm pidfile.temp
fi

sudo fuser -k 55/udp
source config.sh
source unconfig_routes.sh
sudo ./script stop
sudo ps -ef | grep "redsocks" | awk '{print $2}' | xargs kill
sudo ps -ef | grep "openvpn" | awk '{print $2}' | xargs kill