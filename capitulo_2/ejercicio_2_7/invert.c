#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void){
    unsigned x = 0b111000;
    int p = 1;
    int n = 4;

    unsigned set = invert(x,p,n);
    printf("x:%b\ninvert(x,%d,%d):%b\n", x, p, n, set);
}

unsigned invert(unsigned x, int p, int n){
    return x^( ~(~0 << (p + n)) & (~0 << p));
}
