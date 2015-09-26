# All Proxy

[![Build Status](https://travis-ci.org/kunal15595/Allproxy.svg?branch=master)](https://travis-ci.org/kunal15595/Allproxy)

#### We would like to thank the following for their contributions:
-	(Past, present and future) Users, Testers and Debuggers
-	[Redsocks](http://darkk.net.ru/redsocks/)  - an opensource transparent socks redirector that wouldn't work by itself in IITG
-	[ProxyDroid](https://github.com/madeye/proxydroid)  - the open source android app that worked and showed how it can be done
-	[Mini fake DNS server](http://code.activestate.com/recipes/491264-mini-fake-dns-server/)  - a small fake dns server conforming to protocol
-	[Suhail Sherif](https://github.com/suhailsherif) and [Ajaykumar Kannan](https://github.com/ajaykumarkannan) - for [IITG-Transparent-Proxy](https://github.com/suhailsherif/IITG-Transparent-Proxy).
-	[Rajat Khanduja](https://github.com/rajatkhanduja) - for [PyCurl-Downloader](https://github.com/rajatkhanduja/PyCurl-Downloader)
-	(Me)[Kunal Khandelwal](https://github.com/kunal15595) - adding GUI, Openvpn, SSH Tunnel Proxy, Squid Proxy support.
-	**Iptables** - for being so awesome

#### TODO :
- Removing cache entries
- Improvements (Includes analysis of the working of the IITG DNS)

#### HowTo :
- Run install script `sudo -E bash install.sh`
- GUI  `./Allproxy`. Enable/Disable proxies as desired.
- From terminal `gedit config/config.sh`; specify proxy for **nproxy**, and others if required.


#### Tip :
You can use **kde-nm-connection-editor** in package **plasma-nm** to create wireless access-point on your Ubuntu machine.


#### *Tested OS :*
- Ubuntu 14.04
- Linux Mint


#### *Beware !*
Non-authentic DNS servers can be used VERY 	convincingly for phishing. 
Make sure you are in control of your configuration.
