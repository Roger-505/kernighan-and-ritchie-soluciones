#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100

void itoa(int num, char s[]);

static int i = 0;

static void itoa_recursive(int num, char s[]){
    int sign;

    if ((sign = num) < 0){
        num = -num;
        s[i++] = '-';
    }

    if (num / 10)
        itoa_recursive(num / 10, s);
    
    s[i++] = num % 10 + '0';
    s[i] = '\0';
}

void itoa(int num, char s[]){
    itoa_recursive(num, s);
    i = 0;
}

int main(void){
    char s[MAXSIZE];
    int num;

    num = -150;
    itoa(num, s);
    printf("num: %d\nstr: %s\n", num, s);

    num = 150;
    itoa(num, s);
    printf("num: %d\nstr: %s\n", num, s);
}

