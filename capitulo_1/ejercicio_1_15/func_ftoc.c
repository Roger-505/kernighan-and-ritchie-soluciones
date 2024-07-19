#include <stdio.h>

float ftoc(int fahr);

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf(" °F     °C\n");
    while (fahr <= upper)
    {
        celsius = ftoc(fahr);
        print("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float ftoc(int fahr)
{
    int celsius = (5.0/9.0) * (fahr - 32);
    return celsius;
}
