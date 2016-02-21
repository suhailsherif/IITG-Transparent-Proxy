#!/bin/bash
echo "This script stops the transparent proxy and restores the normal behavior"
if [ -f pidfile.temp ] 
then 
	sed 's|[0-9]*|sudo kill &|g' pidfile.temp | bash
	rm pidfile.temp
fi
sudo killall redsocks
./script stop
