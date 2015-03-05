#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }

conn=`nc -zv $1 12121`
echo "$conn"

if [[ $conn == *"succeeded"* ]]
then
	echo "port open"
else
	if [[ $conn == *"No route"* ]]
	then 
		echo "host is down"
	else 
		if [[ $conn == *"Connection refused"* ]]
		then
			echo "port closed"
		fi
	fi
fi

exit 0

case "$2" in
    -g|--get_port)
        nc -zv $2 $3 $4 ;;
    --) break ;;
    *) echo "Internal error!" ; exit 1 ;;
esac