#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse(char s[]);
void itoa_pad(int n, char s[], unsigned pad);

int main(void){
    int num = INT_MIN;
    char str[MAX_SIZE];
    int pad = 5;

    itoa_pad(num, str, pad);

    printf("num, printed as int: %d\nnum, printed as string: %s with padding: %d\n", num, str, pad);   
}

void reverse(char s[]){
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa_pad(int n, char s[], unsigned pad){
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
    
    int len = i;
    
    int k;
    for(k = 0; k < pad; k++)
        s[len + k] = ' ';

    s[len + k] = '\0';
    reverse(s);
}
