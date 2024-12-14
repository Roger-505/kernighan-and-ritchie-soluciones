#include <stdio.h>

void my_strcat(char*,char*);

int main(void){
    char s[100] = "Hola mundo!";

    char *t = " Hoy es un bonito día";

    printf("Antes de strcat:\ns: %s\nt: %s\n", s, t);
    my_strcat(s,t);
    printf("Despues de strcat:\ns: %s\nt: %s\n", s, t);

    return 0;
}

void my_strcat(char *s, char *t){
    while(*s)
        s++;
    while (*s++ = *t++);
}
