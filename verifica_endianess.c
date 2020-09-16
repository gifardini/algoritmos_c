#include <stdio.h>

int main (void){
    int i;
    i = 10;
    printf("Int: %lu bytes\n", sizeof(i));
    printf("Char: %lu bytes\n", sizeof(char));

    char *p = (char *)&i; // retorna o endereço do primeiro bit de i
    int k;

    for(k = 0; k < sizeof(int); k++){
        printf("%.2x \n", *p); // x printa em hexadecimal
        p++;
    }

    /* Da esquerda para a direita:

    Little endian: menos significativos
    Big endian: mais significativos */

    int *l = &i;

    printf("%d\n", sizeof(p));

    return 0;

}

