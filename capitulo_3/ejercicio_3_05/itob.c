#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse(char s[]);
void itob(int n, char s[], int b);

int main(void){
    int num = 4095;
    int base = 16;
    char str[MAX_SIZE];

    itob(num, str, base);

    printf("num, printed as int: %d in base: %d\nnum, printed as string: %s in base: %d\n", num, base, str, base);   
}

void reverse(char s[]){
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b){
    int i, digit;
    
    i = 0;
    do{
        digit = n % b;
        s[i++] = digit >= 10 ? digit - 10 + 'A': digit;
    } while ((n /= b) > 0);

    s[i] = '\0';
    reverse(s);
}

// Solo para enteros positivos
