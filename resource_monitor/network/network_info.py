import psutil


bs = psutil.net_io_counters().bytes_sent
br = psutil.net_io_counters().bytes_recv
ps = psutil.net_io_counters().packets_sent
pr = psutil.net_io_counters().packets_recv
er = psutil.net_io_counters().errin
es = psutil.net_io_counters().errout
di = psutil.net_io_counters().dropin
do = psutil.net_io_counters().dropout

print("number of bytes sent - ",bs)
print("number of bytes received - ",br)
print("number of packets sent - ",ps)
print("number of packets received - ",pr)
print("total number of errors while receiving - ",er)
print("total number of errors while sending - ",es)
print("total number of incoming packets which were dropped - ",di)
print("total number of outgoing packets which were dropped - ",do)
print("\n")