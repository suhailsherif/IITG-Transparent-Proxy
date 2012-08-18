import socket
import base64
import httplib
from threading import Thread
import re

defaultIP='8.8.8.8'

class DNSQuery:
  def __init__(self, data, addr):
    self.data=data
    self.addr=addr
    self.dominio=''
    self.ip=defaultIP

    tipo = (ord(data[2]) >> 3) & 15   # Opcode bits
    if tipo == 0:                     # Standard query
      ini=12
      lon=ord(data[ini])
      while lon != 0:
        self.dominio+=data[ini+1:ini+lon+1]+'.'
        ini+=lon+1
        lon=ord(data[ini])
    if len(self.dominio) > 1 :
      self.dominio=self.dominio[0:-1]

def respuesta(query):
  stat=2
  if dnsCache.__contains__(query.dominio):
    query.ip=dnsCache[query.dominio]
  else:
    query.dominio=query.dominio.replace('_','')
    if query.dominio.lower()[-12:] == '.appspot.com':
      query.ip='74.125.224.208'
      stat=0
    else:
      try:
        dnsConn=httplib.HTTPConnection('gaednsproxy1.appspot.com', timeout=20)
        dnsConn.request("GET", "/?d="+base64.b64encode(base64.b64encode(query.dominio)))
        dnsRes=dnsConn.getresponse()
        query.ip=dnsRes.read()
        if dnsRes.status == 200 :
          stat=1
      except:
        print 'Exception for '+query.dominio
    if re.match('[0-9]+\.[0-9]+\.[0-9]+\.[0-9]', query.ip) and not query.ip == defaultIP:
      dnsCache[query.dominio]=query.ip
    else:
      print 'Error for '+query.dominio
  packet=''
  if query.dominio:
    packet+=query.data[:2] + "\x81\x80"
    packet+=query.data[4:6] + query.data[4:6] + '\x00\x00\x00\x00'   # Questions and Answers Counts
    packet+=query.data[12:]                                         # Original Domain Name Question
    packet+='\xc0\x0c'                                             # Pointer to domain name
    packet+='\x00\x01\x00\x01\x00\x00\x00\x3c\x00\x04'             # Response type, ttl and resource data length -> 4 bytes
    packet+=str.join('',map(lambda x: chr(int(x)), query.ip.split('.'))) # 4bytes of IP
  udps.sendto(packet, query.addr)
  if stat == 1:
    print dnsRes.status, dnsRes.reason, query.dominio, query.ip
  if stat == 2 and not query.dominio == 'gaednsproxy1.appspot.com':
    print 'Result from cache:', query.dominio, query.ip

if __name__ == '__main__':
  print 'DNS server running on port 55.'

  udps = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  udps.bind(('',55))
  
  dnsCache = dict()
  try:
    a=file('defaultIPs','r')
    for i in a:
      dnsCache[i.split()[0]]=i.split()[1]
    a.close()
    print 'Default IPs loaded'
  except:
    print 'Could not load default IPs'
  try:
    a=file('dnsCache','r')
    for i in a:
      dnsCache[i.split()[0]]=i.split()[1]
    a.close()
    print 'Cached IPs loaded'
  except:
    print 'Could not load cached IPs'


  try:
    while 1:
      data, addr = udps.recvfrom(1024)
      p=DNSQuery(data, addr)
      t = Thread(target=respuesta, args=(p,))
      t.start()
  except KeyboardInterrupt:
    print 'Finalizing'
    a=file('dnsCache','w')
    for i in dnsCache:
      a.write(i+'\t'+dnsCache[i]+'\n')
    a.close()
    udps.close()
