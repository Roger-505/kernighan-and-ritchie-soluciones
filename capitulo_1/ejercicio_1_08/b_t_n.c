#include <stdio.h>

int main(void)
{
    int new_line, blank, tab, c;
    new_line = 0;
    blank = 0;
    tab = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            new_line++;
        if (c == '\t')
            tab++;
        if (c == ' ')
            blank++;
    }
    printf("New lines: %d\nTabs: %d\nBlanks: %d\n", new_line, tab, blank);
}
