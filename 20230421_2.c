#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[]){
	int status;
	pid_t pid;
	for(int i=1;i<argc;i++){
		pid=fork();
		if(pid==-1){
			printf("fork failed");
			exit(1);
		}
		else if(pid==0){
			char *args[]={"wc","-l","-w","-c",argv[i],NULL};
			execvp("wc",args);
			exit(1);
		}
	}
	for(int i=1;i<argc;i++){
	 wait(&status);
	}
	return 0;
}
