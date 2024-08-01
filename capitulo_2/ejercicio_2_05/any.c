#include <stdio.h> 

int any(char s1[], char s2[]);

int main(void){
    char s1[] = "Uno 1 Dos 2 Tres 3 Cuatro 4";
    char s2[] = "12345";

    int idx = any(s1, s2);

    printf("s1: %s\ns2: %s\nUbicación de primer char de s2 en s1: %d\n", s1, s2, idx);
}

int any(char s1[], char s2[]){
    int i, k;
    for (k = 0; s2[k] != '\0'; k++){
        for (i = 0; s1[i] != '\0'; i++){
            if (s1[i] == s2[k]){
                return i;
            }
        }
    }
    return -1;
}
