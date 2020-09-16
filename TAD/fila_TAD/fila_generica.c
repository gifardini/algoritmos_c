#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"fila_generica.h"
#include<string.h>

struct fila{
    int inicio, fim, total;
    void **itens;
    int tamElem;
};

fila_t *criar(int tamElem){

    fila_t *f;
    f = (fila_t *)malloc(sizeof(fila_t));
    assert(f != NULL);
    f->itens = (void **)malloc((sizeof(void *)*tam_fila));
    assert(f->itens != NULL);

    f->total = 0;
    f->inicio = 0;
    f->fim = 0;
    f->tamElem = tamElem;
    return f;
}

int isEmpty(fila_t *f){

    assert(f != NULL);
    if (f->total == 0){
        return 1;
    }
    return 0;
}

int isFull(fila_t *f){

    assert(f != NULL);
    if(f->total == tam_fila){
        return 1;
    }
    return 0;
}

int inserir(fila_t *f, void *x){
    if(isFull(f) == 1){
        return 0;
    }
    f->itens[f->fim] = (void *)malloc(f->tamElem);
    assert(f->itens[f->fim] != NULL);
    
    memcpy(f->itens[f->fim], x, f->tamElem);

    f->fim = (f->fim + 1)%tam_fila;
    f->total++;
    return 1;
}

int remover(fila_t *f, void *x){

    if(isEmpty(f) == 1){
        return 0;
    }

    memcpy(x, f->itens[f->inicio], f->tamElem);
    free(f->itens[f->inicio]);
    f->inicio = (f->inicio + 1)%tam_fila;
    f->total--;
    return 1;
}

void destruir(fila_t *f){
    while(f->total > 0){
        free(f->itens[f->inicio]);
        f->total--;
        f->inicio = (f->inicio + 1)%tam_fila;
    }
    /* tem que desalocar item por item antes de desalocar o
    ponteiro itens */

    if(f->itens != NULL)
        free(f->itens);

    if(f != NULL)
        free(f);

    f = NULL;
}