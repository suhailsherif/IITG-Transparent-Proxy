#!/bin/bash
echo "setting default gateway to " $proxy_dns
sudo ip route add to 202.141.80.0/23 via $proxy_dns
sudo ip route del default
sudo ip route add default via $proxy_dns