#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void){
    unsigned x = 0b111000;
    unsigned y = 0b101101;
    int p = 4;
    int n = 3;

    unsigned set = setbits(x,p,n,y);
    printf("x:%b\ny:%b\nsetbits(x,4,3,y):%b\n", x, y, set);
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    return (x >> (p + 1 - n)) | (y & (~0 << n));
}
