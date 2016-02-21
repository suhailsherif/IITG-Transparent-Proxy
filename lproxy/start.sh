#!/bin/bash

source ./config/config.sh
# echo "1" >> new.txt
# sudo echo "2" >> new.txt

sudo mv /etc/squid3/squid.conf /etc/squid3/squid_bak.conf

echo " " > /etc/squid3/squid.conf
echo "acl lan src 10.10.0.0/18" >> /etc/squid3/squid.conf
echo "http_access allow localhost" >> /etc/squid3/squid.conf
echo "http_access allow lan" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 443" >> /etc/squid3/squid.conf
echo "acl SSL_ports port 443" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 80		# http" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 21		# ftp" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 443		# https" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 70		# gopher" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 210		# wais" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 1025-65535	# unregistered ports" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 280		# http-mgmt" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 488		# gss-http" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 591		# filemaker" >> /etc/squid3/squid.conf
echo "acl Safe_ports port 777		# multiling http" >> /etc/squid3/squid.conf
echo "acl CONNECT method CONNECT" >> /etc/squid3/squid.conf
echo "http_port $lproxy_local_port" >> /etc/squid3/squid.conf
# echo "http_port $lproxy_trans_port intercept" >> /etc/squid3/squid.conf
echo "cache_peer $lproxy_server parent $lproxy_port 0 no-query default login=$lproxy_username:$lproxy_password" >> /etc/squid3/squid.conf
echo "never_direct allow all" >> /etc/squid3/squid.conf

sudo squid3
sleep 0.5
echo `ps aux | grep -m 1 -F 'squid3' | grep -v -F 'grep' | awk '{ print $2 }'` > ./pid/lproxy
