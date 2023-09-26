// #include <at89x051.h>
volatile unsigned char P1;
volatile unsigned char P3;

int fib(int n)
{
	if (n <= 1) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

void main(void)
{
	for (unsigned char i = 0; i < 255; i++) {
		int f = fib(i);
		P1 = f >> 8;
		P3 = f;
	}
}

int _sdcc_external_startup()
{
	return 1;
}
