#include <stdio.h>

#define MAX_SIZE 1000

void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);

int main(void){
    /* Escape */
    char s1[] = "Hola,\nsalto de linea\tTabulación";
    char s2[MAX_SIZE];

    escape(s1, s2);
    printf("-- ESCAPE --\n");
    printf("s1:\n%s\ns2, con escape(s1,s2):\n%s\n\n", s1, s2);

    /* Reverse escape */
    reverse_escape(s2, s1);
    printf("-- REVERSE ESCAPE --\n");
    printf("s2:\n%s\ns1, con reverse_escape(s2,s1):\n%s\n", s2, s1);

    return 0;
}

void escape(char s[], char t[]){
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++, j++){
        switch(s[i]){
            case '\n':
                t[j] = '\\';
                t[++j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                t[++j] = 't';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
    t[j] = '\0';  
}

void reverse_escape(char s[], char t[]){
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++, j++){
        switch(s[i]){
            case '\\':
                switch(s[i + 1]){
                    case 'n':
                        t[j] = '\n';
                        i++;
                        break;
                    case 't':
                        t[j] = '\t';
                        i++;
                        break;
                    default:
                        t[j] = s[i];
                        break;
                }
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
    t[j] = '\0';  
}

