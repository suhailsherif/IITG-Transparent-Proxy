# All Proxy

#### We would like to thank the following for their contributions:
-	(Past, present and future) Users, Testers and Debuggers
-	[Redsocks](http://darkk.net.ru/redsocks/)  - an opensource transparent socks redirector that wouldn't work by itself in IITG
-	[ProxyDroid](http://code.google.com/p/proxydroid/)  - the open source android app that worked and showed how it can be done
-	[Mini fake DNS server](http://code.activestate.com/recipes/491264-mini-fake-dns-server/)  - a small fake dns server conforming to protocol
-	[Suhail Sherif](https://github.com/suhailsherif) and [Ajaykumar Kannan](https://github.com/ajaykumarkannan) - for developing it.
-	(Me)[Kunal Khandelwal](https://github.com/kunal15595) - adding support for openvpn(vpnbook)
-	**Iptables** - for being so awesome

#### TODO :
- Removing cache entries
- Licensing
- GUI
- Packaging
- Improvements (Includes analysis of the working of the IITG DNS)

## How To :
(Most of these commands may need superuser priveleges)

Create a file in folder "IITG-Transparent-Proxy" named "config.sh" containing :
```proxy_server=<server>
proxy_port=<port>
proxy_username=<user>
proxy_password=<pass>
vpnbook_username=<vpnbook_user>
vpnbook_password=<vpnbook_pass>
vpnbook_path=<full_path_to_server_conf.ovpn>
```

#### To start :
###### A]	*Simple Way* :

`sudo bash start.sh
`
<br/>
You can edit start.sh if you don't want to enter the proxy details each time.I've included an example.

###### B]	*Difficult Way* :

One-time : In the redsocks folder, "make" to get the executable. 
If make fails, you will need to compile libevent. 
I've included the tar file for it. Or you can download it online.	
<br/>
`./script start
`
<br/>
`sudo python fakeDNS.py
`
<br/>
(defaultIPs has some domains and ip addresses that you might want to have preconfigured)
<br/>
`sh redsocksConfig.sh <proxy_ip> <proxy_port> <username> <password>
`
<br/>
(username and password are optional. You can edit this file to make it prompt you for the username and password if you don't like your credentials in plaintext in your history. And have it delete the redsocksauto.conf that it creates in the redsocks folder.)

#### To stop :
`sudo bash stop.sh
`
<br/>
(Optionally) stop fakeDNS and redsocks.

--------------------

##### *IMPORTANT*:
Edit /etc/resolv.conf and add a line `nameserver 127.0.0.1` at the top.
Or add *127.0.0.1* to your DNS serverlist. The former seems cooler.
<br/>
You can use *kde-nm-connection-editor* in package *plasma-nm* to create wireless access-point on your Ubuntu machine.
<br/>

##### *Tested OS :*
- Ubuntu 14.04 64-bit

<br/>
##### *Beware !*
Non-authentic DNS servers can be used VERY 	convincingly for phishing. 
Make sure you are in control of your configuration.
