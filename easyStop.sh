#!/bin/bash
echo "This script stops the transparent proxy and restores the normal behavior"
sed 's|[0-9]*|sudo kill &|g' pidfile.temp | bash
rm pidfile.temp
sudo killall redsocks
./script stop
