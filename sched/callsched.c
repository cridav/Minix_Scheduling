/* provides _syscall and message*/
#include <lib.h>  
#include </usr/include/minix/type.h>    
#include <stdio.h>
/* provides atoi*/
#include <stdlib.h>

int main(int argc, char **argv) {
    
    int i,n;
/* Minix uses message to pass parameters to a system call*/
    message m;  
/* expecting positive numbers*/
        

    i = atoi(argv[1]);           
    printf("\nYou entered: %d\n",i);

    if (i<0){
       printf("\nNumber not valid\n");
       
       }
       else{
    m.m1_i1 = i;    
    
    n=_syscall(MM_PROC_NR, SETSCHEDULER, &m);
    printf("\nSystem replies: %d\n",n);
        /* _syscall asks the kernel to ask the server process identified by
         * MM_PROC_NR (the MM server process) to execute the system call
         * identified by call number SETSCHEDULER with the parameter in the 
         * message m (accessed through its address &m).
         */
         }   
    return 0;
}
