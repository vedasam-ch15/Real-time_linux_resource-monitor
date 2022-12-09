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

using namespace std;

void cpu_info(){
    cout<<"Cpu info"<<endl;
    char *arg[] = {"python3","/mnt/OS/os_project/cpp/cpu/cpu_info.py",NULL};
    execute_single(arg);
}

void cpu_usage(){
    cout<<"CPU usage : "<<endl;
    char *arg1[] = {"sudo","python3","/mnt/OS/os_project/cpp/cpu/cpu_usage.py",NULL};
    execute_single(arg1);
}

void cpu_temp(){
    cout<<"CPU temperature"<<endl;
    char *arg1[] = {"sensors",NULL};
    execute_single(arg1);
}

void cpu(int& state){
    clear();
    cout<<"CPU"<<endl;
    
    string input;

    int state_cpu = 0;

	while (1) {

        if(state_cpu == 0){
            cout<<"1. Info"<<endl;
            cout<<"2. Usage"<<endl;
            cout<<"3. Temperature"<<endl;

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
                state_cpu = command;
            }
        }
        if(state_cpu == 1){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                cpu_info();
            }
            wait(NULL);
            state_cpu=0;
        }
        else if(state_cpu == 2){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                cpu_usage();
            }
            wait(NULL);
            state_cpu=0;
        }
        else if(state_cpu == 3){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                cpu_temp();
            }
            wait(NULL);
            state_cpu=0;
        }
	}
    state = 0;
}