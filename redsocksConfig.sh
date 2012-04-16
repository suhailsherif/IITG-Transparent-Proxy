#!/bin/sh


echo "
base {
 log_debug = on;
 log_info = on;
 log = stderr;
 daemon = off;
 redirector = iptables;
}


redsocks {
 local_ip = 127.0.0.1;
 local_port = 8123;
 ip = $1;
 port = $2;
 type = http-relay;
 login = \"$3\";
 password = \"$4\";
}
redsocks {
 local_ip = 127.0.0.1;
 local_port = 8124;
 ip = $1;
 port = $2;
 type = http-connect;
 login = \"$3\";
 password = \"$4\";
}
" > redsocks/redsocksauto.conf

sudo ./redsocks/redsocks -c redsocks/redsocksauto.conf
