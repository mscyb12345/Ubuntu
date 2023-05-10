#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	setenv ("MYDATA","5",NULL);
	execl("./test3","test3",NULL);
	return 0;
}
