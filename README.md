# Real-time_linux_resource-monitor
### Real-time user interactive application for Linux has been created that will monitor CPU usage &amp; Memory utilization, I/O devices status, Disk usage, Process, Network monitoring &amp; Hardware information
* The following repository consists of the code files in [here](resource_monitor) and the [final report](Report.pdf) which contains every detail of the project. Along with these, the final presetation for the evaluation has also been added
* For the execution of our program there are some prerequisites that are python3, pip,
psutil (a python library ), lm-sensors(linux tool), keyboard(a python library ), inxi (linux
tool), speedtest-cli (linux tool), inxi(linux tool).
* To check if the above mentioned requirements are met or not:-
  + For checking the version of python, run following command :- 
    > python3 -version
  + If it is not present then install it by using this command :- 
    - > sudo apt-get update
      > sudo apt-get install python3.6
  + For checking whether pip is present is the system or not, run the following
  command :- 
    - > pip --version
  + If it is not present then install it by using this command :- 
    - > sudo apt install python3-pip
  + The rest of the above mentioned requirements can be installed by the following
  commands :- 
    - > sudo apt install inxi
    - > sudo apt install speedtest-cli
    - > sudo apt install lm-sensors
    - > pip install psutil
    - > sudo pip install psutil
    - > pip install python-time
    - > sudo pip install python-time
    - > pip install keyboard
    - > sudo pip install keyboard




