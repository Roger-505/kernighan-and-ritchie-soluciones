#include <stdio.h>
#include <limits.h>
#include <math.h>

unsigned rightrot(unsigned x, int n);

int main(void){
    unsigned x = 0b00010101;
    int n = 4;

    unsigned set = rightrot(x,n);
    printf("x:%032b\nrightrot(x,%d):%032b\n", x, n, set);
    long u_value = (long)UINT_MAX + 1;
}

unsigned rightrot(unsigned x, int n){
    return ( x << (int)( log10( (long)UINT_MAX + 1 ) / log10(2)) - n) | (x >> n);
}

// gcc rightrot.c -lm
