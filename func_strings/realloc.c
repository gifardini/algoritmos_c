#include<stdio.h>

int main(void) {

char *str = (char *)malloc(sizeof(char));
char c;
int i = 0;

    while((c = getchar()) != '\n'){
        str[i++] = c;
        str = (char *)realloc(str, sizeof(char)* (i+1));

    } // \n = enter
str[i] = '\0';

printf("%s, %lu\n", str, sizeof(str));
free(str);

return 0;

// � s� um exemeplo pois na vida isso gasta muita mem�ria pra executar
}
