#include <stdio.h>

#define swap(t,x,y) \
    do{ t temp = x; \
        x = y;      \
        y = temp;   \
    }    while(0)

int main(void){
    int x = 5;
    int y = 2;

    printf("x: %d, y: %d\n", x, y);

    swap(int, x, y);

    printf("swapped\nx: %d, y: %d\n", x, y);
}

