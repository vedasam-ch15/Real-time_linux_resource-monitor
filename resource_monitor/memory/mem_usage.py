import os
import time
import psutil
import keyboard

primary_memory = psutil.virtual_memory().total / (1024.0 ** 3)
used = psutil.virtual_memory().used / (1024.0 ** 3)
available = psutil.virtual_memory().available / (1024.0 ** 3)
percent_used = psutil.virtual_memory().percent

print("Primary Memory","\n")
print("Total Memory : ",primary_memory,"GB")
print("Total Used Memory : ",used,"GB")
print("Total Available Memory : ",available,"GB")
print("percent_used memory: ",percent_used)

swap_memory = psutil.swap_memory().total / (1024.0 ** 3)
used_swap = psutil.swap_memory().used / (1024.0 ** 3)
available_swap = psutil.swap_memory().free / (1024.0 ** 3)
percent_used_swap = psutil.swap_memory().percent
swapped_in_byte = psutil.swap_memory().sin
swapped_out_byte = psutil.swap_memory().sout

print("\nswap Memory \n")
print("Total Swap Memory : ",swap_memory,"GB")
print("Total Used swap Memory : ",used_swap,"GB")
print("Total Available swap Memory : ",available_swap,"GB")
print("percent_used swap memory : ",percent_used_swap)
print("Bytes swapped in : ",swapped_in_byte)
print("Bytes swapped out : ",swapped_out_byte)

def display(mem,bars=50):
    mem_perc = (mem/100.0)
    mem_bar = '*'*int(mem_perc*bars)+'-'*(bars - int(mem_perc*bars))

    print(f"Mem Usage: |{mem_bar} | {mem:.2f}% ",end="\r")

while True:
    if keyboard.is_pressed("q"):
        break
    display(psutil.virtual_memory().percent,50)
    time.sleep(0.5)