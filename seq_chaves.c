/* Giovanna Fardini Lima 10260671 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i, a=0, f=0, tam;
    char string[11];
    printf("Digite a sequencia de chaves: ");
    fflush(stdin);
    gets(string);
    fflush(stdin);

    tam = strlen(string);

     int ans = 0;


    for (i=0; string[i];i++){

        if (string[i] == '{')
            a++;

        if (string[i] == '}'){
            f++;
        }
    }

    for(i=0; string[i]; i++){
        if(string[i] == '}' && a == f && string[i+1] == '{' && string[i+2] == '{')
            ans++;

    }


    for (i=0; string[i]; i++){
        if (string[0] == '}' || a!=f || string[tam-1] == '{')

            ans++;
        }

    if(ans==0)
        printf("\nCorreto.");
    else
        printf("\nErrado.");

    return 0;
}
