import re

dnsCache = dict()
try:
    a=file('./defaultIPs','r')
    for i in a:
    	t=re.split("[, \-!?:\t\n]+", i)
    	dnsCache[t[0]]=t[1]
    a.close()
    print 'Default IPs loaded'
    print dnsCache
except:
    print 'Could not load default IPs'