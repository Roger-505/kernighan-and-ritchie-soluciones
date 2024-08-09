#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int main(void){
    double sum, atof(char s[]);
    char line[MAXLINE];
    int getlinea(char line[], int max);
    
    sum = 0;
    while (getlinea(line,MAXLINE) > 0)
        printf("\t%f\n", atof(line));

    return 0;    
}   

double atof(char s[]){
    double power = 1.0;
    double val, exp;
    int i, sign, signExp;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        signExp = (s[i] == '-') ? -1 : 1;
        
        if (s[i] == '+' || s[i] == '-')
            i++;
        
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
            
        while(exp){
            if (signExp < 0)
                power *= 10.0;
            else 
                power /= 10.0;

            exp--;
        }
    }
    return sign * val / power;
}

int getlinea(char s[], int lim){
    int c, i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

