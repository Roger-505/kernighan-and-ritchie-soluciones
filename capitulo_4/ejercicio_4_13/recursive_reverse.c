#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

void reverse(char s[]);

int main(void){
    char s[] = "Hola mundo";
    char s_rev[MAXSIZE];
    
    strcpy(s_rev, s);
    reverse(s_rev);

    printf("string: %s\nreversed string: %s\n",
            s, s_rev);
}

int i = 0;

void reverse(char s[]){
    int right;
    char temp;

    right = strlen(s) - 1 - i;

    if (right <= i)
        return;

    temp = s[i];
    s[i] = s[right];
    s[right] = temp;
    i++;

    reverse(s);
}
