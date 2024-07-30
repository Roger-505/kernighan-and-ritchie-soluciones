#include <stdio.h>

char lower(char c);

int main(void){
    char caracter = 'A';

    printf("caracter: %c\nlower(caracter): %c\n", caracter, lower(caracter));
}

char lower(char c){
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A': c;
}
