#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

python main.py $1 $2 &

echo $! > $allproxy_path/pid/dproxy #&
