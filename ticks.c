#include <stdint.h>
#include <8051.h>

void main() {
    uint8_t a = 1;
    uint8_t b = 1;
    while (1) {
        uint16_t c = a * b;
        a += c;
        b ^= a;
    }
}

int _sdcc_external_startup()
{
	return 1;
}
