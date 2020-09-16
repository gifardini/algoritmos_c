#include<stdio.h>

char *copia_string(char *str1){
int i=0, j=0;
char *str2;

str2 = (char *)calloc(200, sizeof(char));
if (str2 == NULL){
    printf("Erro memoria insuficiente");
    return NULL;
    }


    while(str2[i] = str1[i]!= '\0'){
    str2[j] = str1[i];
        j++;
        i++;
    }

    return str2;
}

int main (void){

char str1[200];
fflush(stdin);
gets(str1);

printf("A string origem eh: %s\n e a string destino eh: %s", str1, copia_string(str1));

return 0;
}
