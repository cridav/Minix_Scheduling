#include <time.h>
#include <sys/times.h>
#include <sys/types.h>
/* provides _syscall and message*/
#include <lib.h>  
#include </usr/include/minix/type.h>    
#include <stdio.h>
/* provides atoi*/
#include <stdlib.h>

int meta(void);
int main(int argc, char **argv) {
    
    int i,n;
    time_t a,b;
    double t;
    clock_t start, end;
/* Minix uses message to pass parameters to a system call*/
    message m;  
/* expecting positive numbers*/
        

    i = atoi(argv[1]);           
    printf("\nYou entered: %d\n",i);

    if (i>=0&&i<=100){
    m.m1_i1 = i;    
    
    n=_syscall(MM_PROC_NR, SETSCHEDULER, &m);
        /* _syscall asks the kernel to ask the server process identified by
         * MM_PROC_NR (the MM server process) to execute the system call
         * identified by call number SETSCHEDULER with the parameter in the 
         * message m (accessed through its address &m).
         */
	printf("scheduler replies: %d\n",n);
	time (&a);
	meta();
	time (&b);
	t=difftime(b,a);
	printf("\ntime difference: %f\n",t);
      } 
       else{ 
       printf("\nNumber not valid\n");
       }
    return 0;
}
int meta(){
int j;
for(j;j<2000000000;j++){

}





return 0;
}
