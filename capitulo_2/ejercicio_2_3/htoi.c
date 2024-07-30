#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char hex[]);

int main(void){
    char hex[] = "0xffff";
    
    printf("Hex: %s\nInt: %d\n", hex, htoi(hex));
}

int htoi(char hex[]){
    int hex_int = 0;
    char hex_digit;

    for (int i = 0; i < strlen(hex); i++){
        if (hex[i] == 0 && (hex[i + 1] == 'x' || hex[i + 1] == 'X')){
            i += 2;
        }

        if (hex[i] >= 'a' && hex[i] <= 'f'){
            hex_digit = hex[i] - 'a' + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F'){
            hex_digit = hex[i] - 'A' + 10;
        }
        else if (isdigit(hex[i])){
            hex_digit = hex[i] - '0';
        }
        
        hex_int = 16*hex_int + hex_digit;
    }   
    
    return hex_int; 
}
