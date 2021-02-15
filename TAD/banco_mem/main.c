#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"banco_mem.h"

int main(){
    banco_t *b = criar();
    elem x;

    inserir(b, 1);
    inserir(b, 2);
    inserir(b, 3);
    inserir(b, 4);
    inserir(b, 5);
    inserir(b, 7);

    while(!esta_vazio(b)){
        remover(b, &x);
        printf("%d ", x);
    }
    printf("\n");

    return EXIT_SUCCESS;
}