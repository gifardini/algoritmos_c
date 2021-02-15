#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"fila.h"

struct no{
    elem info;
    int prio;
};

struct fila{
    int n;
    no_t *heap[MAX];
};

void sobe(fila_t *f, int i){
    int j; // indice do pai de i
    no_t *temp; //var usada no swap

    j = (int)((i-1)/2);
    
    //se i tem pai e que seja menor que i
    if(j >= 0 && f->heap[i]->prio > f->heap[j]->prio){
        //troca
        temp = f->heap[i];
        f->heap[i] = f->heap[j];
        f->heap[j] = temp;

        //e continua subindo este elem
        sobe(f, j);
    }
}

void desce(fila_t *f, int i){
    int j; //indice do filho de i
    no_t *temp; //var usada no swap

    j = 2*i+1;

    if(j < f->n){ //se i tem filhos
        if(j < f->n-1){ // se i tem filho direto
            //pega o maior filho
            if(f->heap[j]->prio < f->heap[i]->prio){
                j++;
            }
        }
        // e compara com o pai
        if(f->heap[j]->prio > f->heap[i]->prio){
            // swap
            temp = f->heap[i];
            f->heap[i] = f->heap[j];
            f->heap[j] = temp;
            //e continua descendo o mesmo elem
            desce(f, j);
        } 
    }
}

fila_t *criar(){

    fila_t *f;
    f = (fila_t *)malloc(sizeof(fila_t));
    assert(f != NULL);
    f->n = 0;
    return f;
}

int isEmpty(fila_t *f){

    assert(f != NULL);
    return f->n == 0;
}

int isFull(fila_t *f){

    assert(f != NULL);
    return f->n == MAX;
}

int inserir(fila_t *f, elem chave, int prio){
    if(!isFull(f)){
        no_t *p = (no_t *)malloc(sizeof(no_t));
        p->info = chave;
        p->prio = prio;
        f->heap[f->n] = p;
        sobe(f, f->n);
        f->n++;
        return 1;
    }
    return 0;
}

int remover(fila_t *f, elem *chave){

    if(!isEmpty(f)){
        *chave = f->heap[0]->info;
        free(f->heap[0]);
        f->n--;
        f->heap[0] = f->heap[f->n];
        desce(f, 0);
        return 1;
    }
    return 0;
}

void destruir(fila_t *f){
    for(int i = 0; i < f->n; i++){
        free(f->heap[i]);
    }
    free(f);
}
