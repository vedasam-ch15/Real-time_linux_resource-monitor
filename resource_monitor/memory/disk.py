import os
import time
import psutil
import keyboard

print("Disk Partitions :- ")
print(psutil.disk_partitions(),"\n")

print("I/O Data :- ")

print("The number of reads performed - ",psutil.disk_io_counters().read_count)
print("The number of writes performed - ",psutil.disk_io_counters().write_count)
print("The number of bytes read from disk - ",psutil.disk_io_counters().read_bytes)
print("The number of bytes written to the disk - ",psutil.disk_io_counters().write_bytes)
print("The time spent reading from a disk in seconds - ",psutil.disk_io_counters().read_time/1000)
print("The time spent writing to a disk in seconds - ",psutil.disk_io_counters().write_time/1000)
print("The time spent doing actual I/Os operations in seconds - ",psutil.disk_io_counters().busy_time/1000,"\n")

total = psutil.disk_usage('/').total/(1024 ** 3)
used = psutil.disk_usage('/').used/(1024 ** 3)
free = psutil.disk_usage('/').free/(1024 ** 3)
percent = psutil.disk_usage('/').percent

print("Total disk space - ",total," GB")
print("Total Used disk space - ",used," GB")
print("Total free disk space - ",free," GB")
print("Percentage of disk space free - ",100-percent,"%")

print("\n")