#include <time.h>
#include <unistd.h>
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
    
    int i,pidf,n;
    time_t ap,bp,ac,bc;
    double tp,tc,cp,cc,port,num,den;
    clock_t startp, endp,startc,endc;
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

	if(fork()==0){
	startp=clock();
	ap=time(0);
	meta();
	endp=clock();
	bp=time(0);

	cp=(double)(endp-startp)/CLOCKS_PER_SEC;
	tp=bp-ap;
	den=(cp/tp)*100;
	if (i>=50){
	printf("\ntime difference parent: %f\nTIMEp: %f\n",cp,tp);
	
		printf("Portion: %f%%\n",den);
	}
	/*den=tp-cp;*/
	/*den=(cp/tp)*100;
	printf("Percentage: %f%%", den);*/
	}
	else {
	
	ac=time(0);
	startc=clock();
	meta();
	bc=time(0);
	endc=clock();

	cc=(double)(endc-startc)/CLOCKS_PER_SEC;
	tc=bc-ac;
	num=((tc/cc)-1)*100;
	if (i<50){
	printf("\ntime difference child: %f\nTIME: %f\n",cc,tc);
	
		printf("Portion: %f%%\n-",num);
	}
	/*num=tc-cc;*/
	}
	/*port=(tc-cc)/((tp-cp)+(tc-cc))*100;
	printf("\nPercentage: %f, %f",num,den);
	*/
	
      } 
       else{ 
       printf("\nNumber not valid\n");
       }
    return 0;
}
int meta(){
int j,k;
for(j=0;j<2;j++){
for(k=0;k<2000000000;k++);
}





return 0;
}
