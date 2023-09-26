#include <stdint.h>
#include <8051.h>

int dummy_call(void) {
	return 1;
}

void main(void) {
    // STARTING T0 as we want to see the timers even on multi-cycle instructions
    TCON=0x10;

    uint8_t a = dummy_call();
    uint8_t b = dummy_call();
    while (1) {
        uint16_t c = a * b;
        a += c & 0xFF;
        b ^= c >> 8;
    }
}

int _sdcc_external_startup()
{
	return 1;
}
