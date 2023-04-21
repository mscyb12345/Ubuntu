#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
extern char **environ;
int main(){
	while(*environ)
		printf("%s\n",*environ++);
}
