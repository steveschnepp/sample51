#include <stdint.h>
#include <8051.h>

__sbit on;

void main() {
    while(1) {
        P0_0 = 1;
        P0_0 = 0;
        P0_0 = 1;
        P0_0 = 0;
        P0_0 = 1;
        P0_0 = 0;
        P0_0 = 1;
        P0_0 = 0;
        P0_0 = 1;
        P0_0 = 0;
    }
}

int _sdcc_external_startup()
{
	on = 0;
	return 1;
}
