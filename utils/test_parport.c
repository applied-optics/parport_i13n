#include <stdio.h>
#include <stdlib.h>



main(){
int i;
	parport_open("/dev/parport0");
	for(i=0;i<256;i++){
		printf("Writing %d\n",i);
		parport_out(i);
		usleep(50000);
		}
	}
