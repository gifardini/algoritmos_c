#include<stdio.h>
#include<stdlib.h>
#include"listaback.h"
#include<string.h>

int main(){
    
    int n, j;
    lista_t *l = criar();

    char c;

    do{
        scanf("%c", &c);
        if(c == 'i'){
            scanf("%d %d", &n, &j);
            inserir(l, n, j);
        }
        if(c == 'r'){
            scanf("%d", &n);
            remover(l, n);
        }
    }while(c != 'f');
    imprimir(l);
    liberar(l);
    return 0;
}