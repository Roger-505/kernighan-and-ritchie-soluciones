#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%s", line);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;
    int char_found = 0;

    for (i = 0; i < lim - 1 && (c  = getchar()) != EOF && c != '\n'; i++)
    {
        if (c != '\t' && c != ' ' && char_found == 0)
        {
            char_found = 1;
        }
        if (char_found == 1)
        {
            s[i] = c;
        }
    }

    if (char_found == 0)
    {
        return 0;
    }

    if (c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
} 

