#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE    20

#define NOT_INTEGER 0   
#define NOT_FLOAT NOT_INTEGER

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
        return NOT_INTEGER; 
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
        return NOT_INTEGER;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign; 
    if (c != EOF)
        ungetch(c);
    return c; 
}

// Returns:
// - NOT_FLOAT if next input is not a float
// - Positive number if input was valid
// - EOF for end of file
int getfloat(float *pf)
{
    int c, c_sign, int1, int2 = -1, /* initialize to different than zero */ 
        s, sign = 1;                /* *pf > 0 until proven otherwise */

    // *pf = int1.int2
    if ((s = getint(&int1)) == '.')
    {
        /* extract sign and normalize int1 */ 
        sign = int1 < 0 ? -1 : 1; 
        int1 *= sign; 

        (void)getch(); /* discard decimal point */ 
        
        if (!isdigit(c = getch())) /* peek next char */ 
        {
            /* Not a digit. We don't have to process it */ 
            int2 = 0; 
        }
        ungetch(c);

        if (int2 != 0) /* If we need to process it */ 
        {
            /* We are sure this will not fail by this
            * point, so discard return value */ 
            (void)getint(&int2);
        }
    }
    else if (s > 0)
        int2 = 0; 
    else if (s == 0)
    {
        c = getch(); 

        if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
        {
            ungetch(c);
            return NOT_FLOAT; 
        }

        sign = (c == '-') ? -1 : 1; 

        if (c == '+' || c == '-')
        {
            c_sign = c; 
            c = getch(); 
        }

        if (!isdigit(c) && c != '.' && c != EOF)
        {
            ungetch(c);
            ungetch(c_sign);
            return NOT_FLOAT; 
        }

        if (c == '.')  /* This case handles -1 < *pf < 1 */ 
        {
            int1 = 0; 
            s = getint(&int2);
        }
    } /* Fallthrough if s == EOF */ 

    /* Construct float */ 
    int exp = 0; 
    int frac = int2; 
    do
    {
       frac /= 10; 
       exp++;
    } while (frac > 0);

    int div = 1;
    while (exp > 0)
    {
        div *= 10;
        exp--;
    }

    *pf = sign*((float)int1 + ((float)int2)/((float)div));

    return s;
}

int main(void)
{
    int n, x; 
    float array[SIZE]; 

    for (n = 0; n < SIZE && (x = getfloat(&array[n])) != EOF;)
    {
        if (x != 0)
            n++;
        else
            (void)getch(); // Discard non-floats
    }

    for (int c = 0; c < n; c++)
    {
        printf("array[%d] = %f\n", c, array[c]);
    }
    return 0; 
}

// ./a.out < test*txt
