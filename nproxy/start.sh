#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

source ./config/config.sh

sudo cp /etc/environment /etc/environment_bak

echo "http_proxy=http://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/ " > /etc/environment
echo "https_proxy=https://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/ " >> /etc/environment
echo "ftp_proxy=ftp://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/ " >> /etc/environment
echo "socks_proxy=socks://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/ " >> /etc/environment

echo "no_proxy=\"localhost,127.0.0.0/8,::1,*.iitg.ernet.in,*.iitg.ac.in,202.141.80.0/23\" " >> /etc/environment