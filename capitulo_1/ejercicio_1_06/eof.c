#include <stdio.h>

int main()
{
    int c, checkEOF;

    while (1)
    {
        c = getchar();
        checkEOF = (c != EOF);
        if (checkEOF)
            printf("EOF not found, (getchar() != EOF) = %d\n", checkEOF);
        else 
        {
            printf("EOF found, (getchar() != EOF) = %d\n", checkEOF);
            return 0;
        }
    }
}

// ./a.out < test.txt
