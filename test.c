#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
void file1(char *);
int main(int argc, char **argv){
if(argc!=2)exit(0);
file1(argv[1]);
}
void file1(char *filename){
	int fd=open(filename,O_CREAT|O_RDWR,0644);
	char a[1024]="qwertyuiopasdfghjklzxcvbnm";
	int d=strlen(a);
	write(fd,a,d);
	close(fd);
	fd=open(filename,O_RDWR,0644);
	char b[1024]={};
	read(fd,b,d);
	int c=strlen(b);
	close(fd);
	printf("%d\n",c);
}
