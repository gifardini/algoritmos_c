#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"listacruz.h"


int main (){
    matriz_t *m = criar(4, 4);

    insere(m, 0, 1, 1);
    insere(m, 0, 3, 3);
    insere(m, 1, 0, 1);
    insere(m, 2, 1, 2);
    insere(m, 2, 2, 2);

    imprime(m);
    imprime_completa(m);
    printf("\n");

    soma(m, 0, 3, -3);
    imprime_completa(m);
    liberar(m);
    return 0;
}