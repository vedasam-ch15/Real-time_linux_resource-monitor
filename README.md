# Real-time_linux_resource-monitor
### A Real-time user interactive application for Linux has been created that will monitor CPU usage &amp; Memory utilization, I/O devices status, Disk usage, Process, Network monitoring &amp; Hardware information
* The following repository consists of the code files in [here](resource_monitor) and the [final report](Report.pdf) which contains every detail of the project. Along with these, the final presetation for the evaluation has also been added
* [resource_monitor](resource_monitor) contains the various folders each containing a set of functions and [this file](resource_monitor/resource_monitor.cpp) contains the main function which will be executed to give the output of the resource monitor.
* For the execution of our program there are some prerequisites that are python3, pip,
psutil (a python library ), lm-sensors(linux tool), keyboard(a python library ), inxi (linux
tool), speedtest-cli (linux tool), inxi(linux tool).
* To check if the above mentioned requirements are met or not:-
  + For checking the version of python, run following command :- 
    > python3 -version
  + If it is not present then install it by using this command :- 
    > sudo apt-get update <br/>
    > sudo apt-get install python3.6
  + For checking whether pip is present is the system or not, run the following
  command :- 
    > pip --version
  + If it is not present then install it by using this command :- 
    > sudo apt install python3-pip
  + The rest of the above mentioned requirements can be installed by the following
  commands :- 
    > sudo apt install inxi <br/>
    > sudo apt install speedtest-cli <br/>
    > sudo apt install lm-sensors <br/>
    > pip install psutil <br/>
    > sudo pip install psutil <br/>
    > pip install python-time <br/>
    > sudo pip install python-time <br/>
    > pip install keyboard <br/>
    > sudo pip install keyboard
* For running of our program, install the zip file and unzip it.
Open the folder containing the code in the terminal.
  + For compilation:
    > g++ resource_monitor.cpp
  
  + For execution:
    > ./a.out
* While execution of CPU usage and Memory Usage, the program will ask for a password
for your system, enter it then it will be executed.
* For exiting from the live utilization window press _ctrl c_ or _click q_ multiple times.




