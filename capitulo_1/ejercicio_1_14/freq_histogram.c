#include <stdio.h>

#define IN 1 
#define OUT 0
#define MAX_WORD_SIZE 20
#define MAX_WORD_SIZE 20

int main()
{
    int c, nc, state, i, j;
    char word[MAX_WORD_SIZE];

    state = OUT;
    nc = 0;
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            for(i = 0; i < nc; i++)
                putchar(word[i]);
            for(j = 0; j < 10 - i; j++)
                putchar(' ');

            while (nc)
            {
                printf("#");
                nc--;
            }
            putchar('\n');
        }
        else if (state == IN)
        {
            word[nc] = c;
            nc++;
        }
        else if (state == OUT)
        {
            word[nc] = c;
            nc++;
            state = IN;
        }
    }
}

// ./a.out < test.txt
