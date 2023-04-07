#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int filedes;
void finish(){
 printf("end\n");
 close(filedes);
}
int main(){
	ssize_t nread;
	char buffer[1024];
	filedes=open("data.txt",O_RDWR);
	nread=read(filedes,buffer,1024);
	printf("%s\n",buffer);
	atexit(finish);
	exit(0);
}
