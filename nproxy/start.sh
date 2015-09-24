#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment
source /home/$(logname)/.bashrc

source $allproxy_path/config/config.sh

sudo cp /etc/environment /etc/environment_bak
sudo cp /etc/apt/apt.conf /etc/apt/apt.conf_bak

echo "http_proxy=\"http://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\" " > /etc/environment
echo "https_proxy=\"https://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\" " >> /etc/environment
echo "ftp_proxy=\"ftp://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\" " >> /etc/environment
echo "socks_proxy=\"socks://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\" " >> /etc/environment

echo "no_proxy=\"localhost,127.0.0.0/8,::1,*.iitg.ernet.in,*.iitg.ac.in,202.141.80.0/23\" " >> /etc/environment

echo "allproxy_path=$allproxy_path" >> /etc/environment
echo "Acquire::http::proxy \"http://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\"; " > /etc/apt/apt.conf
echo "Acquire::http::proxy \"http://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\"; " >> /etc/apt/apt.conf
echo "Acquire::http::proxy \"http://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\"; " >> /etc/apt/apt.conf
echo "Acquire::http::proxy \"http://$nproxy_username:$nproxy_password@$nproxy_server:$nproxy_port/\"; " >> /etc/apt/apt.conf
