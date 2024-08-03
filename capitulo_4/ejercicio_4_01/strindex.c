#include <stdio.h>

#define MAXLINE 1000

int getlinea(char s[], int lim);
int strindex(char s[], char t[]);

char pattern[] = "lmao";

int main(void){
    char line[MAXLINE];
    int found = 0;
    int idx;

    while (getlinea(line, MAXLINE) > 0)
        if ((idx = strindex(line, pattern)) >= 0){
            printf("%s", line);
            found++;
            printf("idx: %d\n", idx);
        }
    return found;
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

int strindex(char s[], char t[]){
    int i, j, k;
    
    int len = 0;
    while (s[++len] != '\0');   

    for (i = len - 1; i >= 0; i--){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}
