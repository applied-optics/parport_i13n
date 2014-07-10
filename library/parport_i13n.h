#ifndef _PARPORT_I13N_H_
#define _PARPORT_I13N_H_

void parport_open(const char *name);
void parport_close(void);
void parport_out(unsigned char data);
void parport_bit_up(unsigned char bit);
void parport_bits_up(unsigned char bit);
void parport_bit_down(unsigned char bit);
void parport_bits_down(unsigned char bit);
void parport_bit_set(unsigned char bit, int val);
unsigned char parport_value(void);
unsigned char parport_n2b(int n);

#endif
