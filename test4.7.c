#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
 int main(/*int argc,char *argv[]*/){
//  if(argv[1]<=0){
  // printf("error\n");
 ///  exit(0);
 // }
 // int a=*argv[1];
  int a=3;
  pid_t pid;
  pid=fork();
 if(pid==0){
   int sum=1;
   for(int i=2;i<=a;i++)sum*=i;
   printf("child : %d\n",sum);
  }
  else if(pid>0){
   int sum=0;
   for(int i=1;i<=a;i++)sum+=i;
   printf("parent : %d\n",sum);
  }
   else {
	printf("fail");
 }
 }
