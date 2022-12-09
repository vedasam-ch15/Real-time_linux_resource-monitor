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

void other(int& state){
    clear();
    cout<<"Other Info :- "<<endl;

    int pid = fork();
    if(pid < -1)
        exit(1);
    if(pid == 0){
        char *arg[] = {"python3","/mnt/OS/os_project/cpp/Others/other.py",NULL};
        execute_single(arg);
    }
    wait(NULL);
    
    state = 0;
}