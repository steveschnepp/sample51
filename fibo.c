#include <stdio.h>
#include <8051.h>

typedef unsigned long fibo_t;

int putchar(int ch){
	while(!TI);
	TI = 0;
	SBUF = ch;
	return 0;
}

static
fibo_t fibo(fibo_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    fibo_t fn1 = 1;
    fibo_t fn2 = 1;
    fibo_t fn = 0;
    for (fibo_t i = 1; i < n; i ++) {
        fn = fn1 + fn2;
        fn2 = fn1;
        fn1 = fn; 
    }

    return fn;
}

void printFib(int n)
{
    static fibo_t i;
    for (i = 1; i < n; i ++) {
        static fibo_t f;
        f = fibo(i);
        printf("%d ", i);
    }
}

// driver code
int main()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
	TI=1;

    static int n = 32;
    printFib(n);
    return 0;
}
