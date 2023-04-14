#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<time.h>
int main(){
	pid_t pid;
	time_t result;
	char buffer[1024];
	int filedes=open("./curtime.txt",O_RDWR|O_CREAT,0644);
		if((pid=fork())>0){
			sleep(1);
			wait(1);
		}
		else if(pid==0){
			setsid();
			while(1){
				result=time(NULL);
				strcpy(buffer,asctime(localtime(&result)));
				write(filedes,buffer,strlen(buffer));
				printf("%s\n",buffer);
				sleep(10);
			}
		}
}
