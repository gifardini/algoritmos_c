#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"listagen.h"

int main(){
    no_t *l1 = concat(atomo(3), atomo(4));
    no_t *l2 = sublista(l1);
    l2 = concat(l2, atomo(2));
    no_t *l = concat(atomo(1), l2);
    imprimir(l); 

    if(esta_na_lista(l, 4)){
        printf("esta na lista\n");
    }

    no_t *l_2 = concat(atomo(1), atomo(2));
    l_2 = concat(atomo(3), atomo(4));

    no_t *l_3 = concat(atomo(1), l2);

    if(compara_listas(l_2, l)){
        printf("l_2 e l iguais");
    }
    if(compara_listas(l_3, l)){
        printf("l_3 e l iguais\n");
    }
    printf("Profundida l_2 = %d\n", profundidade(l_2));
    printf("Profundidade l = %d", profundidade(l));    
    libera(l);
    return 0;
}