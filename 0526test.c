#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#define SIZE 512

int main(){
	char *msg="test";
	char buffer[SIZE];
	int p1[2],p2[2],nread,i;
	pipe(p1);
	pipe(p2);
	pid_t pid1,pid2;

	pid1=pid2=0;
	pid1=fork();
	if(pid1>0){
		pid2=fork();
	}

	if(pid1>0&&pid2>0){
		close(p1[0]);
		close(p2[0]);
		write(p1[1],msg,SIZE);
		write(p2[1],msg,SIZE);
		printf("parent message\n");
	}

	else if(pid1==0&&pid2==0){
		close(p2[0]);
		close(p2[1]);
		close(p1[1]);
		nread=read(p1[0],buffer,SIZE);
		printf("child1,%s\n",buffer);
	}

	else if(pid1>0&&pid2==0){
		close(p1[0]);
		close(p1[1]);
		close(p2[1]);
		nread=read(p2[0],buffer,SIZE);
		printf("child2,%s\n",buffer);
	}
	else exit(1);
}
