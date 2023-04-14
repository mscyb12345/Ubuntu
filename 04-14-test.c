#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	pid_t pid;
	int status=0;
	if((pid=fork())>0){
		int sum1=1;
		while(!waitpid(pid,&status,WNOHANG)){
			for(int i=0;i<y;i++){
				sum1*=x;
			}
			printf("parent sum: %d\n",sum1);
			sleep(2);
		}
		printf("all sum : %d\n",sum1+(status>>8));
	}
	else if(pid==0){
		sleep(1);
		int sum2=0;
		for(int i=x;i<=y;i++){
		 sum2+=i;
		}
		printf("child sum: %d\n",sum2);
		exit(sum2);
	}
	else
		printf("fail");
	return 0;
}
