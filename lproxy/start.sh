#!/bin/bash

source ./config/config.sh

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
echo "http_port $lproxy_port" >> /etc/squid3/squid.conf
echo "http_port $lproxy_trans_port intercept" >> /etc/squid3/squid.conf
echo "cache_peer $lproxy_proxy_server parent $lproxy_proxy_port 0 no-query default login=$lproxy_proxy_username:$lproxy_proxy_password" >> /etc/squid3/squid.conf
echo "never_direct allow all" >> /etc/squid3/squid.conf

sudo squid3
echo `ps aux | grep -F 'squid3' | grep -v -F 'grep' | awk '{ print $2 }'` > ./pid/lproxy