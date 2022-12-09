import psutil
import datetime

# name: the name of the user.
# terminal: the tty or pseudo-tty associated with the user, if any, else None.
# host: the host name associated with the entry, if any.
# started: the creation time as a floating point number expressed in seconds since the epoch.
# pid: the PID of the login process (like sshd, tmux, gdm-session-worker, …). On Windows and OpenBSD this is always set to None.

print("User :- ",psutil.users()[0].name)
print("Terminal :- ",psutil.users()[0].terminal)
print("Host :- ",psutil.users()[0].host)
print("PID of login process :- ",psutil.users()[0].pid)
print("The system boot time expressed in seconds since the epoch :- ",psutil.boot_time(),"seconds")
print("Time of start of system :- ",datetime.datetime.fromtimestamp(psutil.boot_time()).strftime("%Y-%m-%d %H:%M:%S"))


print("Sensors Temperatures :- ")
print(psutil.sensors_temperatures())

print()
print("Fan sensor :- ")
print(psutil.sensors_fans())

print()
print("Battery :- ")
print("Percent",psutil.sensors_battery().percent)
print("Seconds left",psutil.sensors_battery().secsleft)
print("Power plugged :- ",psutil.sensors_battery().power_plugged)