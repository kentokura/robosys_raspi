#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int pid = fork(); //子なら0,親なら子のpid.

	//child
	if (pid == 0){
		while(1){
			sleep(1);
			puts("child");
		}
		exit(0);
	}	

	//parent
	while(1){
		sleep(1);
		puts("parent");
	}
	exit(0);
}	
