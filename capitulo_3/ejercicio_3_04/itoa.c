#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void){
    int num = -2147483648;
    char str[MAX_SIZE];

    itoa(num, str);

    printf("num, printed as int: %d\nnum, printed as string: %s\n", num, str);   
}

void reverse(char s[]){
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]){
    int i, sign;
    int largest = 0;

    if(((sign = n) < 0) && n > INT_MIN)
        n = -n;
    else if (n == INT_MIN){
        n = -(INT_MIN + 1);
        largest = 1;
    }
    
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0){
        s[i++] = '-';
        if (largest)
            s[0] += 1;
    }

    s[i] = '\0';
    reverse(s);
}
