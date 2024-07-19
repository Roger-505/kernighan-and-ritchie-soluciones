#include <stdio.h>

#define MAX_CHAR_AMOUNT 256

int main()
{
    char char_num[MAX_CHAR_AMOUNT];
    int c;

    for (int i = 0; i < MAX_CHAR_AMOUNT; i++)
        char_num[i] = 0; 

    while ((c = getchar()) != EOF)
        ++char_num[c];

    printf("character frequencies\n");
    for (int i = 0; i < MAX_CHAR_AMOUNT; i++)
    {
        if (char_num[i] != 0)
        {
            if (i == '\n')
                printf("\\n      : ");
            else if (i == '\t')
                printf("\\t      : ");
            else if (i == ' ')
                printf("espacio : ");
            else
                printf("%c       : ", i);

            for (int j = char_num[i]; j > 0; j--)
            {
                putchar('#');
            }
            putchar('\n');
        }
    }

}

// ./a.out < freq_histogram.c | less
