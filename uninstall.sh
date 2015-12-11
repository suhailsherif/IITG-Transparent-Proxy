#!/bin/bash

## force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

## run only inside Allproxy folder
cd "$(dirname "$0")"

sudo echo "Uninstalling Allproxy."


if [ -d $HOME/.allproxy ]; then
	rm -rf $HOME/.allproxy
fi

## global directory
if [ -d /etc/allproxy ]; then
	sudo rm -rf /etc/allproxy
fi

## set allproxy path
cur_path=$(pwd)

## remove application entry in dash

if [ -d /usr/share/applications ]; then
	sudo rm -f /usr/share/applications/allproxy.desktop
fi

# turn off automatic dnsmasq
if [ -f /etc/NetworkManager/NetworkManager.conf ]; then
	sudo sed -i "s/# dns=dnsmasq/dns=dnsmasq/g" /etc/NetworkManager/NetworkManager.conf
fi

if [ -f /usr/lib/python$python_version/downloader.py ]; then
	sudo rm -f /usr/lib/python$python_version/downloader.py
fi

if [ -f /usr/bin/pycurl-download ]; then
	sudo rm -f /usr/bin/pycurl-download
fi

if [ -f /var/log/downloader.log ]; then
	sudo rm -f /var/log/downloader.log
fi

## remove allproxy folder
rm -rf .

## restart network manager 
sudo service network-manager restart