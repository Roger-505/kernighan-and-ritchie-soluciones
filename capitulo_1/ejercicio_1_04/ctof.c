#include <stdio.h>

void main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 160;
    step = 20;

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }   
}
