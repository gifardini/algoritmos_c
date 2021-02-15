#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"lista_v.h"

typedef struct no no_t;

struct no{
    elem info;
    no_t *ant, *prox;
};

struct lista{
    no_t *inicio, *fim;
};

lista_t *criar(){
    lista_t *p;
    p = (lista_t *)malloc(sizeof(lista_t));
    p->inicio = NULL;
    p->fim = NULL;

    return p;
}

void liberar(lista_t *l){
    if(l != NULL){
        no_t *aux = l->inicio;
        while(aux != NULL){
            l->inicio = l->inicio->prox;
            free(aux);
            aux = l->inicio;
        }
        free(l);
    }
}

int inserir(lista_t *l, elem x){
    assert(l != NULL);

    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->info = x;
    p->prox = NULL;
    p->ant = NULL;

    no_t *aux, *ant;
    ant = NULL;
    aux = l->inicio;

    while(aux != NULL && x > aux->info){
        ant = aux;
        aux = aux->prox;
    }

    // caso x já existe na lista
    if(aux != NULL && x == aux->info){
        free(p);
        return 0; // n inseriu o elemento.
    }

    if(ant == NULL){ //lista vazia ou inserindo no inicio
        p->prox = l->inicio;
        if(l->inicio != NULL){
            l->inicio->ant = p;
        }
        l->inicio = p;
    }
    else{ //inserindo no meio ou no fim
        p->prox = ant->prox;
        ant->prox = p;
        if(p->prox != NULL){ //inserindo no meio
            p->prox->ant = p;
        }
        else{
            l->fim = p;
        }
        p->ant = ant;
    }
    return 1;

}

int remover(lista_t *l, elem x){
    assert(l != NULL);

    no_t *p = l->inicio;
    no_t *ant = NULL;

    while(p != NULL && x > p->info){
        ant = p;
        p = p->prox;
    }
    if(p == NULL || p->info != x){
        return 0;
    }

    if(ant == NULL){ //remove o 1 elemento
        l->inicio = l->inicio->prox;
        if(l->inicio != NULL){
            l->inicio->ant = NULL;
        }
        else{
            l->fim = NULL;
        }
        free(p);
    }
    else{ // remove no meio ou no fim
        if(p->prox == NULL){ // remove do fim
            l->fim = p->ant;
            ant->prox = NULL;
            free(p);
        }
        else{ // remove do meio
        ant->prox = p->prox;
        p->prox->ant = ant;
        free(p);
        }
    }
    return 1;
}

void imprimir(lista_t *l){
    no_t *p = l->inicio;
    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void imprimir_inv(lista_t *l){
    no_t *p = l->fim;
    while(p != NULL){
        printf("%d ", p->info);
        p = p->ant;
    }
    printf("\n");
}