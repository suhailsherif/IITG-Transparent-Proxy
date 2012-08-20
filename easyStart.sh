#!/bin/bash
echo "This is the easy version of starting up the transparent proxy."
echo "The backend needs to compiled. I've done that in the script itself."
echo "In case make fails, you will need to compile libevent. I've included the tar for it. Extract it and use the readme file. "

echo "You will need to give the sudo password when requested."

sleep 1;

make -C ./redsocks/

# Comment this section out and use the arugements directly if you prefer that. I've given an example in the next commented section
read -p "Enter the proxy address: " proxy
read -p "Enter the proxy port: " port
read -p "Enter your proxy username: " username
read -s -p "Enter your proxy password: " password

# Uncomment this section to use details stored in the file
#proxy=202.141.80.22
#port=3128
#username=<username>
#password=<passwd>

sudo echo "Got sudo rights"
./script start & 
./redsocksConfig.sh $proxy $port $username $password & 
sudo python fakeDNS.py &
echo $! > pidfile.temp
