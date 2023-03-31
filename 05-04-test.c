#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc , char *argv[]){
 DIR *dirp;
 struct dirent *dentry;
 if((dirp=opendir(argv[1]))==NULL)
  printf("nodirectory\n");
 else printf("find directory\n");
}
