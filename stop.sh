#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source /etc/allproxy/config
source $allproxy_path/config/config.sh

case $1 in
tproxy)
	source $allproxy_path/tproxy/stop.sh &
;;
vproxy)
	source $allproxy_path/vproxy/stop.sh &
;;
lproxy)
	source $allproxy_path/lproxy/stop.sh &
;;
sproxy)
	source $allproxy_path/sproxy/stop.sh &
;;
tproxy)
	source $allproxy_path/tproxy/stop.sh &
;;
fproxy)
	source $allproxy_path/fproxy/stop.sh &
;;
cproxy)
	source $allproxy_path/cproxy/stop.sh &
;;
all)
	source $allproxy_path/sproxy/stop.sh &
	source $allproxy_path/tproxy/stop.sh &
	source $allproxy_path/lproxy/stop.sh &
	source $allproxy_path/vproxy/stop.sh &
	source $allproxy_path/cproxy/stop.sh &
	source $allproxy_path/fproxy/stop.sh &
;;
*) 
	source $allproxy_path/config/config.sh
	source $allproxy_path/config/unconfig_routes.sh >> $allproxy_path/log/unconfig_routes
;;
esac
