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


void hw_system(){
    cout<<"System Hardware info :- ";
    char *arg1[] = {"inxi","-S","-c","30",NULL};
    execute_single(arg1);

    char *arg2[] = {"inxi","-M","-c","30",NULL};
    execute_single(arg2);
}

void hw_cpu(){
    cout<<"CPU Hardware info :- ";
    char *arg1[] = {"inxi","-C","-c","30",NULL};
    execute_single(arg1);
}

void hw_graphics(){
    cout<<"Graphics Hardware info :- ";
    char *arg1[] = {"inxi","-G","-c","30",NULL};
    execute_single(arg1);
}

void hw_audio(){
    cout<<"Audio Hardware info :- ";
    char *arg1[] = {"inxi","-A","-c","30",NULL};
    execute_single(arg1);
}

void hw_network(){
    cout<<"Audio Hardware info :- ";
    char *arg1[] = {"inxi","-N","-c","30",NULL};
    execute_single(arg1);
}

void hw_drivers(){
    cout<<"Audio Hardware info :- ";
    char *arg1[] = {"inxi","-D","-c","30",NULL};
    execute_single(arg1);
}

void hw_sensors(){
    cout<<"Audio Hardware info :- ";
    char *arg1[] = {"inxi","-s",NULL};
    execute_single(arg1);
}

void hardware(int& state){
    clear();
    cout<<"Hardware: "<<endl;
    
    string input;

    int state_har = 0;

	while (1) {

        if(state_har == 0){
            cout<<"1. System"<<endl;
            cout<<"2. CPU"<<endl;
            cout<<"3. Graphics"<<endl;
            cout<<"4. Audio"<<endl;
            cout<<"5. Network"<<endl;
            cout<<"6. Drivers"<<endl;
            cout<<"7. Sensors"<<endl;

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
                state_har = command;
            }
        }
        if(state_har == 1){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                hw_system();
            }
            wait(NULL);
            state_har = 0;
        }
        else if(state_har == 2){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                hw_cpu();
            }
            wait(NULL);
            state_har=0;
        }
        else if(state_har == 3){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                hw_graphics();
            }
            wait(NULL);
            state_har=0;
        }
        else if(state_har == 4){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                hw_audio();
            }
            wait(NULL);
            state_har=0;
        }
        else if(state_har == 5){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                hw_network();
            }
            wait(NULL);
            state_har=0;
        }
        else if(state_har == 6){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                hw_drivers();
            }
            wait(NULL);
            state_har=0;
        }
        else if(state_har == 7){
            int pid = fork();
            if(pid < -1)
                exit(1);
            if(pid == 0){
                hw_sensors();
            }
            wait(NULL);
            state_har=0;
        }
	}
    state = 0;
}