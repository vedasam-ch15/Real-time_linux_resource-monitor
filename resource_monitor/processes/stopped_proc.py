import psutil
import getpass
from pprint import pprint as pp

print("Processes stopped with respective pids are: ")
print(pp([(p.pid, p.info) for p in psutil.process_iter(['name', 'status']) if p.info['status'] == psutil.STATUS_STOPPED]))
print("\n")