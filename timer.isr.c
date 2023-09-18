#include <8051.h>

#define IDLE() do { PCON |= IDL; } while(0)
#define _nop_() __asm__("nop")

int _sdcc_external_startup()
{
	return 1;
}

volatile unsigned char v;

void timer0_isr(void) __interrupt(TF0_VECTOR) __using(3)
{
	v++;
	if (v == 0x10) {
		P3_7 = !P3_7;
		v = 0;
	}
}

inline
void yield() {
	IDLE();
}

void main()
{
	v = 0;

	P0=0x00;
	TMOD=0x02; 	// 8bit auto reload mode for timer 0
	TH0=0xE0; 	// Upper Timer Register
	TL0=0xE0; 	// Lower Timer Register
	TCON=0x10; 	// Start Timer 0
	IE=0x82;   	// Enable Timer 0 overflow interrupt
	while(1) {
		yield();
	}
}
