#include <stdio.h> 

void squeeze_str(char s1[], char s2[]);

int main(void){
    char s1[] = "Uno 1 Dos 2 Tres 3 Cuatro 4";
    char s1_copy[] = "Uno 1 Dos 2 Tres 3 Cuatro 4";
    char s2[] = "12345";

    squeeze_str(s1, s2);

    printf("s1: %s\ns2: %s\nNuevo s1: %s\n", s1_copy, s2, s1);
}

void squeeze_str(char s1[], char s2[]){
    int i, j, k;
    for (k = 0; s2[k] != '\0'; k++){
        for (i = j = 0; s1[i] != '\0'; i++){
            if (s1[i] != s2[k]){
                s1[j++] = s1[i];
            }
        }
        s1[j] = '\0';
    }
}
