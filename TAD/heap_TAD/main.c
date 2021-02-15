#include <stdio.h>
#include "fila.h"

int main(){
    fila_t *f = criar();
    elem x;

    inserir(f, 4, 5);
    inserir(f, 7, 1);
    inserir(f, 2, 3);
    inserir(f, 8, 9);

    while(!isEmpty(f)){
        remover(f, &x);
        printf("%d ", x); //imprimir na ordem da prio: 8, 4, 2, 7
    }

    destruir(f);
    return 0;
}
