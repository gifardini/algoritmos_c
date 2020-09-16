#include<stdio.h>
#include<stdlib.h>
#include"pilha_generica.h"

typedef struct ponto{
    int x, y;
}ponto_t;

int main (){

    pilha_t *p;
    int i;

    p = create(sizeof(ponto_t));
    ponto_t ponto;
    for(i = 0; i < 10; i++){
        ponto.x = i;
        ponto.y = -i;
        push(p, &ponto); // pq ponto nao eh ponteiro, se fosse n precisava do &
    }

    while(!isEmpty(p)){
        pop(p, &ponto);
        printf("(%d, %d)", ponto.x, ponto.y);
    }

    destroy(p);

    return 0;
}
