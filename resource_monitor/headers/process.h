#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<dirent.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include<fcntl.h>
#include<bits/stdc++.h>
#include "basic.h"

void cpu_extensive(){
    cout<<"Top 10 CPU extensive perocesse are :- "<<endl;
    char *arg[] = {"inxi","-t","c10","-c","30",NULL};
    execute_single(arg);
}

void mem_extensive(){
    cout<<"Top 10 Memory extensive perocesse are :- "<<endl;
    char *arg[] = {"inxi","-t","m10","-c","30",NULL};
    execute_single(arg);
}

void all_pids(){
    cout<<"All the pids of all the processes are :-"<<endl;
    char *arg[] = {"python3","/mnt/OS/os_project/cpp/processes/all_pids.py",NULL};
    execute_single(arg);
}

void sleep_proc(){
    char *arg[] = {"python3","/mnt/OS/os_project/cpp/processes/sleeping_proc.py",NULL};
    execute_single(arg);
}

void stop_proc(){
    char *arg[] = {"python3","/mnt/OS/os_project/cpp/processes/stopped_proc.py",NULL};
    execute_single(arg);
}

void process(int& state){
    clear();
    cout<<"Process "<<endl;
    
    string input;

    int state_proc = 0;

	while (1) {

        if(state_proc == 0){
            cout<<"1. CPU extensive processes"<<endl;
            cout<<"2. Memory extensive processes"<<endl;
            cout<<"3. All PIDs"<<endl;
            cout<<"4. Sleeping Processes"<<endl;
            cout<<"5. Stopped processes"<<endl;

            cout<<"Enter the command : ";
            cin>>input;
            
            if(input == "help"){
                cout<<"For going back type back"<<endl;
            }

            else if(input == "back"){
                break;
            }

            else{
                int command = stoi(input);
                cout<<command<<endl;
                state_proc = command;
            }
        }
        if(state_proc == 1){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                cpu_extensive();
            }
            wait(NULL);
            state_proc = 0;
        }
        else if(state_proc == 2){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                mem_extensive();
            }
            wait(NULL);
            state_proc=0;
        }
        else if(state_proc == 3){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                all_pids();
            }
            wait(NULL);
            state_proc=0;
        }
        else if(state_proc == 4){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                sleep_proc();
            }
            wait(NULL);
            state_proc=0;
        }
        else if(state_proc == 5){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                stop_proc();
            }
            wait(NULL);
            state_proc=0;
        }
	}
    state = 0;
}