#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

echo "This script stops the transparent proxy and restores the normal behavior"

case $1 in
tproxy)
	source ./tproxy/stop.sh &
;;
vproxy)
	source ./vproxy/stop.sh &
;;
lproxy)
	source ./lproxy/stop.sh &
;;
sproxy)
	source ./sproxy/stop.sh &
;;
*) 
	sudo fuser -k 55/udp
	source ./config/config.sh
	source ./config/unconfig_routes.sh
;;
esac
