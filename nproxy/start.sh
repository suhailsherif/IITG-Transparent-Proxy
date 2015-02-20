#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

sudo cp /etc/environment /etc/environment_bak

echo "http_proxy=http://$proxy_username:$proxy_password@$proxy_server:$proxy_port/ " >> /etc/environment
echo "https_proxy=https://$proxy_username:$proxy_password@$proxy_server:$proxy_port/ " >> /etc/environment
echo "ftp_proxy=ftp://$proxy_username:$proxy_password@$proxy_server:$proxy_port/ " >> /etc/environment
echo "socks_proxy=socks://$proxy_username:$proxy_password@$proxy_server:$proxy_port/ " >> /etc/environment

echo "no_proxy=\"localhost,127.0.0.0/8,::1,*.iitg.ernet.in,*.iitg.ac.in,202.141.80.0/23\" " >> /etc/environment