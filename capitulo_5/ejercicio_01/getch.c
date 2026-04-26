#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE    20

/* return value of getint() when next char is not a digit */ 
#define NOT_DIGIT   0   
char buf[BUFSIZE];
int bufp = 0; 

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c; 
}

int getint(int *pn)
{
    int c, sign, c_sign; 

    while (isspace(c = getch())); /* skip whitespace */

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0; 
    }

    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-')
    {
        c_sign = c;
        c = getch(); 
    }

    if (!isdigit(c) && c != EOF) /* skip single + and - */ 
    {
        ungetch(c);
        ungetch(c_sign);
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign; 
    if (c != EOF)
        ungetch(c);
    return c; 
}

int main(void)
{
    int n, x, array[SIZE]; 

    for (n = 0; n < SIZE && (x = getint(&array[n])) != EOF;)
    {
        if (x != 0)
            n++;
        else
            (void)getch(); // Discard non-ints
    }

    for (int c = 0; c < n; c++)
    {
        printf("array[%d] = %d\n", c, array[c]);
    }
    return 0; 
}

// a.out < array.txt
