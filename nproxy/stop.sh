#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

sudo cp /etc/environment_bak /etc/environment