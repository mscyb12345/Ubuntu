#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
 DIR *dirp;
 struct dirent *dentry;
 int a=0;
 dirp=opendir(".");
 while(dentry=readdir(dirp)){
  if(dentry->d_ino!=0)
   a++;
 }
 printf("%d\n",a);
 closedir(dirp);
}
