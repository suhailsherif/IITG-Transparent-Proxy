#!/bin/bash

# force bash
[ -z $BASH ] && { exec bash "$0" "$@" || exit; }
source /etc/environment
source $allproxy_path/config/config.sh

IP=$(ifconfig | grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1' | grep -m 1 -Eo '([0-9]*\.){3}[0-9]*')

INPUT=$allproxy_path/fproxy/cmdin

while [ -f $allproxy_path/pid/fproxy ]
do
	
	while IFS='#' read -r ip kind filetype filename id port;do

	    echo "ip: " $ip >> $allproxy_path/log/fproxy
	    echo "kind: " $kind >> $allproxy_path/log/fproxy
	    echo "filetype: " $filetype >> $allproxy_path/log/fproxy
	    echo "filename: " $filename >> $allproxy_path/log/fproxy
	    echo "id: " $id >> $allproxy_path/log/fproxy
	    echo "port: " $port >> $allproxy_path/log/fproxy
	    echo "----------------------------" >> $allproxy_path/log/fproxy
	    
	    tail -n +2 "$INPUT" > $INPUT
	    case $kind in 
    	request)

	    	zenity --question --text="Accept $filetype $filename from $ip ?" --ok-label="Yes" --cancel-label="No"
	    	if [ $? = 0 ] ; then
	    		echo "request accepted" >> $allproxy_path/log/fproxy
	    		echo "----------------------------" >> $allproxy_path/log/fproxy
	    		next_port=$(bash $allproxy_path/fproxy/port.sh 12122 30 2>/dev/null)	
	    		if [ ! $next_port -eq 0 ];then
	    			msg="$IP#accepted###$id#$next_port"
	    			echo $msg >> $allproxy_path/log/fproxy
	    			echo "----------------------------" >> $allproxy_path/log/fproxy
	    			echo $msg | ncat $ip 12121
	    		fi
	    	else
	    		echo "request rejected" >> $allproxy_path/log/fproxy
	    		echo "----------------------------" >> $allproxy_path/log/fproxy
	    		msg="$IP#rejected###$id#"
	    		echo $msg >> $allproxy_path/log/fproxy
	    		echo "----------------------------" >> $allproxy_path/log/fproxy
	    		echo $msg | ncat $ip 12121
	    	fi
		;;
		accepted)

			sudo -u $USER  DISPLAY=":0.0" notify-send "File Transfer - Request accepted" 
			source $allproxy_path/config/config.sh
			msg="$IP#initiated###id#$port"
			echo $msg >> $allproxy_path/log/fproxy
			echo "----------------------------" >> $allproxy_path/log/fproxy
			echo $msg | ncat $ip 12121
			cd $(dirname "${fproxy_upload_path}")
			tar -cz "$(basename ${fproxy_upload_path})" | ncat -l -p $port &
			cd $allproxy_path
		;;
		rejected)

			sudo -u $USER  DISPLAY=":0.0" notify-send "File Transfer - Request denied" 
		;;
		initiated)

			sudo -u $USER  DISPLAY=":0.0" notify-send "File Transfer - Starting download" 
			source $allproxy_path/config/config.sh
			ncat $ip $port | tar -xz -C "$fproxy_download_path" &
		;;
		*)
		;;
		esac

	done < $INPUT
	sleep 2
	if [ ! -f  $allproxy_path/pid/fproxy ]; then
		kill $$
	fi
done

