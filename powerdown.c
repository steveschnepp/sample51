#include <8051.h>
	
int _sdcc_external_startup()
{
	return 1;
}

void main()
{
	SCON = 0x40;
	TMOD = 0x20;
	TH1 = 0xF0;
	TL1 = TH1;
	TR1 = 1;
	IE |= 0x82; // Setup the ISR for T1
	IE |= 0x90; // Setup the ISR for SERIAL
	TI = 1; // Free to send
	PCON |= (1<<1); // Power down
}
