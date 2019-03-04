#include <time.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/types.h>
/* provides _syscall and message*/
#include <lib.h>    
#include <stdio.h>
/* provides atoi*/
#include <stdlib.h>

int meta(void);
int main(int argc, char **argv) {
    
    int i,pidf,n;
    time_t a,b;
    double t;
    clock_t start, end;
    message m;  
        


    	
	
	fork();
	start=clock();
	a=time(0);
	meta();
	end=clock();
	b=time(0);
	t=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time: %f ",t);	
	t=b-a;
	printf("\nTIME: %f\n",t);
	return 0;
}
int meta(){
int i;
	for(i=0;i<2000000000;i++);
return 0;
}
