import psutil

def speed_NIC():
    keys = list(psutil.net_if_stats().keys())
    values = list(psutil.net_if_stats().values())
    for i in range(len(keys)):
        key = keys[i]
        value = values[i]
        print(key, " : ", value[2]," mega bits")
        
print("The speeds of all network interface card are: ")
speed_NIC()
print("\n")