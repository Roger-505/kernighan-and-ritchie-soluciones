#include <stdio.h> 

#define TRUE 1
#define FALSE 0
#define IN 1 
#define OUT 0
#define MAX_WORD_SIZE 10
#define MAX_WORDS 30

int main()
{
    int c, nc, state, i, j, wc, char_printed;
    char word[MAX_WORD_SIZE];
    int word_sizes[MAX_WORDS];
    
    state = OUT;
    nc = 0;
    wc = 0;
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            for(i = 0; i < nc; i++) { putchar(word[i]); } 
            for(j = 0; j < MAX_WORD_SIZE - i; j++) { putchar(' '); }
            
            word_sizes[wc++] = nc;
            nc = 0;
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
    putchar('\n');

    char_printed = TRUE;    
    
    while (char_printed == TRUE)
    {
        char_printed = FALSE;
        for (int i = 0; i < wc; i++)
        {
            if (word_sizes[i] != 0)
            {
                putchar('#');
                for(j = 0; j < MAX_WORD_SIZE - 1; j++) { putchar(' '); }

                char_printed = TRUE;
                word_sizes[i]--;
            } else
            {
                for(j = 0; j < MAX_WORD_SIZE; j++) { putchar(' '); }
            }
        }
        putchar('\n');
    }
}

// ./a.out < test.txt
