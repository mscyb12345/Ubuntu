#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	char buffer[1024];
	if(readlink(argv[1],buffer,1024)!=-1)
		printf("find softlink\n");
	else printf("no softlink\n");
}
