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

void mem_info(){
    cout<<"Memory info"<<endl<<endl;
    char *arg1[] = {"cat","/proc/meminfo",NULL};
    char *arg2[] = {"grep","Cached",NULL};
    execute_grep(arg1,arg2);

    char *arg3[] = {"grep","Dir",NULL};
    execute_grep(arg1,arg3);

    char *arg4[] = {"grep","Writeback",NULL};
    execute_grep(arg1,arg4);

    char *arg5[] = {"grep","KernelStack",NULL};
    execute_grep(arg1,arg5);

    char *arg6[] = {"grep","PageTables",NULL};
    execute_grep(arg1,arg6);

    char *arg7[] = {"grep","Percpu",NULL};
    execute_grep(arg1,arg7);
    cout<<endl;
}

void mem_usage(){
    cout<<"Memory usage"<<endl;
    char *arg[] = {"sudo","python3","/mnt/OS/os_project/cpp/memory/mem_usage.py",NULL};
    execute_single(arg);
}

void disk(){
    cout<<"Disk Usage"<<endl;
    char *arg[] = {"python3","/mnt/OS/os_project/cpp/memory/disk.py",NULL};
    execute_single(arg);
}

void mem(int& state){
    clear();
    cout<<"Memory"<<endl;
    
    string input;

    int state_mem = 0;

	while (1) {

        if(state_mem == 0){
            cout<<"1. Info"<<endl;
            cout<<"2. Usage"<<endl;
            cout<<"3. Disk"<<endl;

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
                state_mem = command;
            }
        }
        if(state_mem == 1){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                mem_info();
            }
            wait(NULL);
            state_mem = 0;
        }
        else if(state_mem == 2){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                mem_usage();
            }
            wait(NULL);
            state_mem=0;
        }
        else if(state_mem == 3){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                disk();
            }
            wait(NULL);
            state_mem=0;
        }
	}
    state = 0;
}