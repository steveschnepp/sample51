#include <stdint.h>
#include <8051.h>

uint16_t  f;

uint16_t b2gray(uint16_t i) {
	return (i >> 1) ^ i;
}

uint16_t b2bcd(uint16_t b) {
	uint16_t bcd = 0;
	bcd |= (b % 10) << 0; b /= 10;
	bcd |= (b % 10) << 4; b /= 10;
	bcd |= (b % 10) << 8; b /= 10;
	bcd |= (b % 10) << 12; b /= 10;
	return bcd;
}

int main()
{
	while(1) {
		uint16_t f_gray = b2gray(f);
		P0 = (f      >> 0) & 0xFF;
		P2 = (f_gray >> 0) & 0xFF;

		uint16_t f_bcd = b2bcd(f);
		P1 = (f_bcd >> 0) & 0xFF;
		P3 = (f_bcd >> 8) & 0xFF;
		f++;
	}
}

int _sdcc_external_startup()
{
	f = 0;
	return 1;
}

