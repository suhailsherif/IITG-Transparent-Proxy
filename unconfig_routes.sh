#!/bin/bash

sudo ip route del 202.141.80.0/23 via $proxy_dns
sudo ip route del default
sudo ip route add default via $restore_dns