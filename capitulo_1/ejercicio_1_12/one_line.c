#include <stdio.h>

#define IN 1 
#define OUT 0

int main()
{
    int c, state;

    state = I;
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            putchar('\n');
        }
        else if (state == OUT) {
            state = IN;
            putchar(c);
        }
        else if (state == IN)
        {
            putchar(c);
        }
    }
}

// ./a.out < hola.txt
