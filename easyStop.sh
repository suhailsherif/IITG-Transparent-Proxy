#!/bin/bash
echo "This script stops the transparent proxy and restores the normal behavior"
sudo killall python
sudo killall redsocks
./script stop
