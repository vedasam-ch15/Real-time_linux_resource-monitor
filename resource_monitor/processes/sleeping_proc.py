import psutil
import getpass
from pprint import pprint as pp

print("Processes sleeping with respective pids are: ")
print(pp([(p.pid, p.info) for p in psutil.process_iter(['name', 'status']) if p.info['status'] == psutil.STATUS_SLEEPING]))
print("\n")
