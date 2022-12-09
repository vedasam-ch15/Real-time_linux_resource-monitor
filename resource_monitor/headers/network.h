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


void network_info(){
    char *arg[] = {"python3","/mnt/OS/os_project/cpp/memory/disk.py",NULL};
    execute_single(arg);
}

void network_speed(){
    char *arg[] = {"python3","/mnt/OS/os_project/cpp/network/speed_nic.py",NULL};
    execute_single(arg);
}

void net_speed_test(){
    char *arg[] = {"speedtest",NULL};
    execute_single(arg);
}

void network(int& state){
    clear();
    cout<<"Memory"<<endl;
    
    string input;

    int state_net = 0;

	while (1) {

        if(state_net == 0){
            cout<<"1. Network Info"<<endl;
            cout<<"2. Network interface speeds"<<endl;
            cout<<"3. net speed test"<<endl;

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
                state_net = command;
            }
        }
        if(state_net == 1){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                network_info();
            }
            wait(NULL);
            state_net = 0;
        }
        else if(state_net == 2){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                network_speed();
            }
            wait(NULL);
            state_net=0;
        }
        else if(state_net == 3){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                net_speed_test();
            }
            wait(NULL);
            state_net=0;
        }
	}
    state = 0;
}