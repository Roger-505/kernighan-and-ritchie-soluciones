#include <stdio.h>

unsigned bitcount(unsigned x);

int main(void){
    unsigned x = 0b101011;
    
    printf("x: %b\nbitcount(x): %u\n", x, bitcount(x));
}

unsigned bitcount(unsigned x){
    unsigned b;
    while(x){
        x &= (x - 1);
        b++;
    }

    return b;
}
