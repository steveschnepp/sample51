#include <stdint.h>
#include <string.h>
#include <8051.h>

#define __builtin_nop() __asm nop __endasm;

char BUF[3];

#define delay_100ns() __builtin_nop();
#define delay_300ns() delay_100ns(); delay_100ns(); delay_100ns();

void reset_ws281x() {
	P1_0 = 0;
	// delay 50us
	for (int i = 50000 / 300; i; i --) {
		delay_300ns();
	}
}

void sendbyte(uint8_t u) {
	P3 = u;
	for (uint8_t i = 8; i ; i --) {
		if (u & 0b10000000) {
			P1_0 = 1;
			delay_300ns();
			delay_300ns();
			delay_300ns();
			P1_0 = 0;
		} else {
			P1_0 = 1;
			delay_300ns();
			P1_0 = 0;
		}
		u <<= 1;
	}
}

int main()
{
	for (int i = 0; i < sizeof(BUF); i ++) {
		BUF[i] = i + 0xF;
	}

	while(1) {
		P1_1 = 0;
		P1_1 = 1;
		reset_ws281x();
		static uint8_t u = 0;
		for (uint8_t i = 0; i < 3*6; i ++) {
			sendbyte(u++);
		}
	}
}

int _sdcc_external_startup()
{
	memset(BUF, 0, sizeof(BUF));
	return 1;
}
