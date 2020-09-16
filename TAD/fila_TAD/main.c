#include<stdio.h>
#include"fila.h"

int main(){
    fila_t *f;
    int i;
    elem x;
    f = criar();
    for(i = 0; i < 10; i++){
        inserir(f, i);
    }
    while(!isEmpty(f)){
        remover(f, &x);
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
