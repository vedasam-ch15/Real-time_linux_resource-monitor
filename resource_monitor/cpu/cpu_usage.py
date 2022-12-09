import os
import time
import psutil
import keyboard

print("The CPU times for all the current CPUs:")
print(psutil.cpu_times(True))

print("\n")
print("Average CPU usage percentage - ")
print(psutil.cpu_percent(interval=1))
print("\n")

print("Each CPU core usage :- ")
per_cpu = psutil.cpu_percent(interval=1, percpu=True)
for idx, usage in enumerate(per_cpu):
    print(f"CORE_{idx+1}: {usage}%")

print("\n")

print("Real time CPU Usage : ")

def display(cpu,bars=50):
    cpu_perc = (cpu/100.0)
    cpu_bar = '*'*int(cpu_perc*bars)+'-'*(bars - int(cpu_perc*bars))
    print(f"CPU Usage: |{cpu_bar} | {cpu:.2f}% ",end="\r")

while True:
    if keyboard.is_pressed("q"):
        break
    display(psutil.virtual_memory().percent,50)
    time.sleep(0.5)