#include <at89x051.h>

#define _nop_() __asm__("nop")

unsigned char c1 = 1;
unsigned char c3 = 1;

void delay_us(unsigned int us)
{
	TMOD = 0x01;
	TH0 = (us >> 8) & 0xFF;
	TL0 = (us >> 0) & 0xFF;
	TR0 = 1;
	while (!TF0);
	TF0 = 0;
	TR0 = 0;
}

void spinloop(unsigned int iterations)
{
	for (; iterations; iterations--) {
		_nop_();
	}
}

void main()
{
	while (1) {
		P1 = c1;
		c1 = (c1 >> 1) | (c1 << 7);
		delay_us(10000);
		P3 = c3;
		c3 = (c3 << 1) | (c3 >> 7);
		spinloop(10000);
	}
}
