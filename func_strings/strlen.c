#include<stdio.h>
#include<string.h>

int conta_string (char *str){
int cont = 0;

while(*(str+cont) != '\0'){

    cont++;
    }
    return cont;
}


int main (void){

char string[100];

    fflush(stdin);
    gets(string);

    printf("%lu bytes \n", conta_string(string));

    return 0;

}
