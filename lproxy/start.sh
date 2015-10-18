#!/bin/bash

source /etc/allproxy/config
source $allproxy_path/config/config.sh

echo "
confdir /etc/privoxy
logdir /var/log/privoxy
actionsfile match-all.action # Actions that are applied to all sites and maybe overruled later on.
actionsfile default.action   # Main actions file
actionsfile user.action      # User customizations
filterfile default.filter
filterfile user.filter      # User customizations
logfile logfile
toggle  1
enable-remote-toggle  0
enable-remote-http-toggle  0
enable-edit-actions 0
enforce-blocks 0
buffer-limit 4096
enable-proxy-authentication-forwarding 1
forwarded-connect-retries  0
accept-intercepted-requests 0
allow-cgi-request-crunching 0
split-large-forms 0
keep-alive-timeout 5
tolerate-pipelining 1
socket-timeout 300
connection-sharing 1

# forward   			/	$lproxy_username:$lproxy_password@$lproxy_server:$lproxy_port
forward   			/	$lproxy_server:$lproxy_port
# forward-socks5 	/ 	127.0.0.1:9050 .
# forward-socks4a 	/	127.0.0.1:9050 .
# listen-address  localhost:$lproxy_local_port
# listen-address  127.0.0.1:$lproxy_local_port
listen-address 0.0.0.0:$lproxy_local_port

" > $allproxy_path/config/config_lproxy

privoxy --no-daemon --pidfile $allproxy_path/pid/lproxy $allproxy_path/config/config_lproxy

