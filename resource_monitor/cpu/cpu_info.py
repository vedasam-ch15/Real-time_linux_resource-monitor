import os
import time
import psutil

print("No of CPU - ",end="")
print(psutil.cpu_count())

print("No of context switches - ",end="")
print(psutil.cpu_stats().ctx_switches)

print("No of interrupts - ",end="")
print(psutil.cpu_stats().interrupts)

print("No of soft interrupts - ",end="")
print(psutil.cpu_stats().soft_interrupts)

print("Current frequency of CPU - ",end='')
print(psutil.cpu_freq().current)

print("Max frequency of CPU - ",end='')
print(psutil.cpu_freq().max)

print("Min frequency of CPU - ",end='')
print(psutil.cpu_freq().min)