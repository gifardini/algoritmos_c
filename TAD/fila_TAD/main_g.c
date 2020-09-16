#include<stdio.h>
#include<stdlib.h>
#include"fila_generica.h"

typedef struct ponto{
    int x, y;
}ponto_t;

int main (){

    fila_t *f;
    int i;

    f = criar(sizeof(ponto_t));
    ponto_t ponto;
    for(i = 0; i < 10; i++){
        ponto.x = i;
        ponto.y = -i;
        inserir(f, &ponto); // pq ponto nao eh ponteiro, se fosse n precisava do &
    }

    while(!isEmpty(f)){
        remover(f, &ponto);
        printf("(%d, %d)", ponto.x, ponto.y);
    }

    destruir(f);

    return 0;
}
