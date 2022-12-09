import psutil

print(psutil.sensors_fans())

print(psutil.sensors_temperatures(fahrenheit=False))

print(psutil.sensors_battery())