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

bool isint(string s){
    for(auto i:s){
        int val = i-'0';
        if(val < 0 | val > 9)
            return false;
    }
    return true;
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


void cpu_info(){
    clear();
    cout<<"Cpu info : "<<endl<<endl;
    char *arg[] = {"python3","cpu/cpu_info.py",NULL};
    execute_single(arg);
}

void cpu_usage(){
    clear();
    cout<<"CPU usage : "<<endl<<endl;
    char *arg1[] = {"sudo","python3","cpu/cpu_usage.py",NULL};
    execute_single(arg1);
}

void cpu_temp(){
    clear();
    cout<<"CPU temperature : "<<endl<<endl;
    char *arg1[] = {"sensors",NULL};
    execute_single(arg1);
}

void cpu(int& state){
    clear();
    string input;

    int state_cpu = 0;

	while (1) {

        if(state_cpu == 0){
            cout<<endl;
            cout<<"CPU"<<endl<<endl;
            cout<<"1. Info"<<endl;
            cout<<"2. Usage"<<endl;
            cout<<"3. Temperature"<<endl;
            cout<<"Enter back to go to previous window"<<endl<<endl;

            cout<<"Enter the command : ";
            cin>>input;
            
            if(input == "help"){
                cout<<"For going back type back"<<endl;
            }

            else if(input == "back"){
                clear();
                break;
            }

            else if(isint(input)){
                int command = stoi(input);
                state_cpu = command;
            }
            else{
                cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
                state_cpu = 0;
                continue;
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
            cout<<endl;
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
            cout<<endl;
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
            cout<<endl;
        }
        else{
            cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
            state_cpu = 0;
        }
	}
    state = 0;
}

void mem_info(){
    cout<<"Memory info"<<endl<<endl;
    char *arg1[] = {"cat","/proc/meminfo",NULL};
    char *arg2[] = {"grep","Cached",NULL};
    execute_grep(arg1,arg2);

    char *arg3[] = {"grep","Dirty:",NULL};
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
    cout<<"Memory usage"<<endl<<endl;
    char *arg[] = {"sudo","python3","memory/mem_usage.py",NULL};
    execute_single(arg);
}

void disk(){
    cout<<"Disk Usage"<<endl<<endl;
    char *arg[] = {"python3","memory/disk.py",NULL};
    execute_single(arg);
}

void mem(int& state){
    clear();
    
    string input;

    int state_mem = 0;

	while (1) {

        if(state_mem == 0){
            cout<<endl;
            cout<<"Memory"<<endl<<endl;
            cout<<"1. Info"<<endl;
            cout<<"2. Usage"<<endl;
            cout<<"3. Disk"<<endl;
            cout<<"Enter back to go to previous window"<<endl<<endl;

            cout<<"Enter the command : ";
            cin>>input;
            
            if(input == "help"){
                cout<<"For going back type back"<<endl;
            }

            else if(input == "back"){
                clear();
                break;
            }

            else if(isint(input)){
                int command = stoi(input); 
                state_mem = command;
            }
            else{
                cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
                state_mem = 0;
                continue;
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
        else{
            cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
            state_mem = 0;
        }
	}
    state = 0;
}

void network_info(){
    char *arg[] = {"python3","network/network_info.py",NULL};
    execute_single(arg);
}

void network_speed(){
    char *arg[] = {"python3","network/speed_nic.py",NULL};
    execute_single(arg);
}

void net_speed_test(){
    char *arg[] = {"speedtest",NULL};
    execute_single(arg);
}

void network(int& state){
    clear();
    
    string input;

    int state_net = 0;

	while (1) {

        if(state_net == 0){
            cout<<endl;
            cout<<"Network"<<endl<<endl;
            cout<<"1. Network Info"<<endl;
            cout<<"2. Network interface speeds"<<endl;
            cout<<"3. net speed test"<<endl;
            cout<<"Enter back to go to previous window"<<endl<<endl;

            cout<<"Enter the command : ";
            cin>>input;
            
            if(input == "help"){
                cout<<"For going back type back"<<endl;
            }

            else if(input == "back"){
                clear();
                break;
            }

            else if(isint(input)){
                int command = stoi(input);
                cout<<command<<endl;
                state_net = command;
            }
            else{
                cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
                state_net = 0;
                continue;
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
        else{
            cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
            state_net = 0;
        }
	}
    state = 0;
}

void cpu_extensive(){
    cout<<"Top 10 CPU intensive perocesse are :- "<<endl;
    char *arg[] = {"inxi","-t","c10","-c","30",NULL};
    execute_single(arg);
}

void mem_extensive(){
    cout<<"Top 10 Memory intensive perocesse are :- "<<endl;
    char *arg[] = {"inxi","-t","m10","-c","30",NULL};
    execute_single(arg);
}

void all_pids(){
    cout<<"All the pids of all the processes are :-"<<endl;
    char *arg[] = {"python3","processes/all_pids.py",NULL};
    execute_single(arg);
}

void sleep_proc(){
    char *arg[] = {"python3","processes/sleeping_proc.py",NULL};
    execute_single(arg);
}

void stop_proc(){
    char *arg[] = {"python3","processes/stopped_proc.py",NULL};
    execute_single(arg);
}

void process(int& state){
    clear();
    
    string input;

    int state_proc = 0;

	while (1) {
        if(state_proc == 0){
            cout<<endl;
            cout<<"Process "<<endl<<endl;
            cout<<"1. CPU intensive processes"<<endl;
            cout<<"2. Memory intensive processes"<<endl;
            cout<<"3. All PIDs"<<endl;
            cout<<"4. Sleeping Processes"<<endl;
            cout<<"5. Stopped processes"<<endl;
            cout<<"Enter back to go to previous window"<<endl<<endl;

            cout<<"Enter the command : ";
            cin>>input;
            
            if(input == "help"){
                cout<<"For going back type back"<<endl;
            }

            else if(input == "back"){
                clear();
                break;
            }

            else if(isint(input)){
                int command = stoi(input);
                state_proc = command;
            }
            else{
                cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
                state_proc = 0;
                continue;
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
        else{
            cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
            state_proc = 0;
        }
	}
    state = 0;
}

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
    
    string input;

    int state_har = 0;

	while (1) {

        if(state_har == 0){
            cout<<endl;
            cout<<"Hardware: "<<endl<<endl;
            cout<<"1. System"<<endl;
            cout<<"2. CPU"<<endl;
            cout<<"3. Graphics"<<endl;
            cout<<"4. Audio"<<endl;
            cout<<"5. Network"<<endl;
            cout<<"6. Drivers"<<endl;
            cout<<"7. Sensors"<<endl;
            cout<<"Enter back to go to previous window"<<endl<<endl;

            cout<<"Enter the command : ";
            cin>>input;
            
            if(input == "help"){
                cout<<"For going back type back"<<endl;
            }

            else if(input == "back"){
                clear();
                break;
            }

            else if(isint(input)){
                int command = stoi(input);
                state_har = command;
            }
            else{
                cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
                state_har = 0;
                continue;
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
        else{
            cout<<endl<<"Please, Enter correct command !!!"<<endl<<endl;
            state_har = 0;
        }
	}
    state = 0;
}

void other(int& state){
    clear();
    cout<<"Other Info :- "<<endl;

    int pid = fork();
    if(pid < -1)
        exit(1);
    if(pid == 0){
        char *arg[] = {"python3","Others/other.py",NULL};
        execute_single(arg);
    }
    wait(NULL);
    
    state = 0;
    cout<<endl<<endl;
}

int main()
{
    string input;
	clear();


    int state = 0;

	while (1) {

        if(state == 0){
            cout<<"Type help"<<endl<<endl;
            cout<<"1. CPU"<<endl;
            cout<<"2. Memory"<<endl;
            cout<<"3. Network"<<endl;
            cout<<"4. Process"<<endl;
            cout<<"5. Hardware"<<endl;
            cout<<"6. Other"<<endl;
            cout<<"Enter exit to close the program"<<endl<<endl;

            cout<<"Enter the command : ";
            cin>>input;
            
            if(input == "help"){
                cout<<"For exiting type exit"<<endl;
                cout<<"For going back, type back"<<endl;
                continue;
            }

            else if(input == "exit"){
                clear();
                cout<<"Thank You for using our real time resource monitor for linux !!!"<<endl<<endl;
                break;
            }

            else if(isint(input)){
                int command = stoi(input);
                state = command;
            }

            else{
                cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
                state = 0;
                continue;
            }
        }
        if(state == 1){
            cpu(state);
        }
        else if(state == 2){
            mem(state);
        }
        else if(state == 3){
            network(state);
        }
        else if(state == 4){
            process(state);
        }
        else if(state == 5){
            hardware(state);
        }
        else if(state == 6){
            other(state);
        }
        else{
            cout<<endl<<"please, Enter correct command !!!"<<endl<<endl;
            state = 0;
        }
	}
	return 0;
} 