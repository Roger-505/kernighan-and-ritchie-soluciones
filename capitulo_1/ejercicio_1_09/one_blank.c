#include <stdio.h>

int main(void)
{
    int c;
    int blank = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && blank == 0) 
        {
            putchar(c);
            blank = 1;
        }
        else if (c != ' ' && blank == 1)
        {
            putchar(c);
            blank = 0;
        } 
        else if (c != ' ')
        {
            putchar(c);
        }
    }
}
