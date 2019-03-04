#include<time.h>
#include<stdio.h>

int main(void){
int i;
time_t start, end;
double timediff;
time(&start);
printf("Starting timer\nSleeping for 5 seconds\n");
for (i=0;i<10456000;i++){
printf(".");
}
time(&end);
timediff=difftime(end,start);
printf("time difference: %f\n",timediff);




return 0;
}
