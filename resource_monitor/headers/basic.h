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

using namespace std;

void clear(){
	printf("\033[H\033[J");
	return;
}

int execute_single(char *arg[]){
    int val = execvp(arg[0],arg);
    if(val==-1){
        printf("Error while compiling reverse\n");
        return 3;
    }
}
  
int execute_grep(char *arg1[],char *arg2[]){
    int fd[2];
    if(pipe(fd)==-1){
        return 1;
    }

    int pid1 = fork();
    if(pid1 < 0){
        printf("Error while creating 1st child\n");
        return 2;
    }
    if(pid1==0){
        dup2(fd[1],STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        int val = execvp(arg1[0],arg1);
        if(val==-1){
            printf("Error while compiling reverse 1\n");
            return 3;
        }
    }

    int pid2 = fork();
    if(pid2 < 0){
        printf("Error while creating 1st child\n");
        return 2;
    }
    if(pid2==0){
        dup2(fd[0],STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);

        int val = execvp(arg2[0],arg2);
        if(val==-1){
            printf("Error while compiling reverse 2\n");
            return 3;
        }
    }
    
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
}