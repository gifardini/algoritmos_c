#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"ab.h"


int main (){

    int n; 

    scanf("%d", &n);
    arvore_t *T = criar();
    int pai = -1, avo;

    for(int i = 0; i < n; i++){
        int id, esq, dir;
            scanf("%d %d %d", &id, &esq, &dir);
            inserir_esq(T, id, pai);
            inserir_esq(T, esq, id);
            inserir_dir(T, dir, id);
            if(esq != -1 && dir != -1){
                avo = pai;
                pai = id; 
            }
    }

    pai = -1;
    imprimir_elem(T->raiz, pai);
    finalizar(T->raiz);
    return 0;   
}