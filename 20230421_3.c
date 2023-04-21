#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	char *envlist[]={"MYDATA=5",NULL};
	execl("./test3","test3",NULL,envlist,NULL);
	return 0;
}
