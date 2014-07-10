#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/ppdev.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "parport_i13n.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int parport_dev=0;
int open_count=0;
unsigned char parport_data=0;

void parport_open(char * name){
	if(open_count<1){	/* should be able to open parport multiple times, need to keep track */
		parport_dev=open(name,O_RDWR);
		if(parport_dev<0){
			printf("parport: fatal error cannot open \"%s\"\n",name);
			printf("Error number is %d\n",errno);
			perror("parport_open: error");
			exit(1);
			}
		/* set up exclusive rights to the parport */
		ioctl(parport_dev,PPEXCL); /* note that robi doesn't use this....*/
		ioctl(parport_dev,PPCLAIM);
		// for the shutters expt we have to leave the state unknow until we set it
		//parport_data=0;
		//parport_out(parport_data);
		ioctl(parport_dev,PPRDATA,&parport_data);
		}
	open_count++;
	}
	
void parport_close(void){
	if(open_count==1){
		ioctl(parport_dev,PPRELEASE);
		close(parport_dev);
		}
	open_count--;
	}

void parport_out(unsigned char data){
unsigned char there;
	if(ioctl(parport_dev,PPWDATA,&data)==0)
		parport_data=data;
	}

// these work with a bit mask - changing the 1s in the mask leaving the 0s
void parport_bits_up(unsigned char bit){
        parport_out(bit | parport_data);
        }
void parport_bits_down(unsigned char bit){
        parport_out(~bit & parport_data);
        }
// these set the bit 0-7 only
void parport_bit_up(unsigned char bit){
	parport_out((1<<bit) | parport_data);
	}
void parport_bit_down(unsigned char bit){
	parport_out(~(1<<bit) & parport_data);
	}

// bits labelled 0-7
void parport_bit_set(unsigned char bit,int val){
	if(val)parport_bit_up(bit);
	else parport_bit_down(bit);
	}
unsigned char parport_value(){
        return parport_data;
        }

unsigned char parport_n2b(int n){
        return 1 << n;
        }








