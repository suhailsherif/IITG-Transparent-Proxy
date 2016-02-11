#!/bin/bash
source /etc/environment

source $allproxy_path/config/config.sh

echo " " > $allproxy_path/config/lproxy.conf
echo "

acl lan src 10.10.0.0/18 172.16.0.0/12 			# LAN
acl lan src 10.42.0.0/18 192.168.0.0/18 		# WIFI
http_access allow lan
http_access allow localhost
acl SSL_ports port 443
acl Safe_ports port 443			# ssl
acl Safe_ports port 80			# http
acl Safe_ports port 21			# ftp
acl Safe_ports port 443			# https
acl Safe_ports port 70			# gopher
acl Safe_ports port 210			# wais
acl Safe_ports port 1025-65535	# unregistered ports
acl Safe_ports port 280			# http-mgmt
acl Safe_ports port 488			# gss-http
acl Safe_ports port 591			# filemaker
acl Safe_ports port 777			# multiling http
acl CONNECT method CONNECT
http_port $lproxy_local_port
http_port 9898 transparent
cache_peer $lproxy_server parent $lproxy_port 0 no-query default login=$lproxy_username:$lproxy_password
# cache_peer_access $lproxy_server allow lannever_direct allow all
cache_dir ufs $allproxy_path/cache 100 16 256

" > $allproxy_path/config/lproxy.conf

sudo squid3 -N -f $allproxy_path/config/lproxy.conf

sleep 0.5
echo `ps aux | grep -m 1 -F 'squid3' | grep -v -F 'grep' | awk '{ print $2 }'` > $allproxy_path/pid/lproxy

