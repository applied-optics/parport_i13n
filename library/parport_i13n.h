#ifndef _PARPORT_I13N_H_
#define _PARPORT_I13N_H_

void parport_open(char *);
void parport_close(void);
void parport_out(unsigned char);
void parport_bit_up(unsigned char);
void parport_bits_up(unsigned char);
void parport_bit_down(unsigned char);
void parport_bits_down(unsigned char);
void parport_bit_set(unsigned char, int);
unsigned char parport_value(void);
unsigned char parport_n2b(int);

#endif
