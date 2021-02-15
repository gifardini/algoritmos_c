#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"lista_j.h"

typedef struct no no_t;

struct no{
    elem info;
    no_t *prox;
};

struct lista{
    no_t *senti;
    int tam;
};

lista_t *cria(){
    lista_t *l;
    l = (lista_t *)malloc(sizeof(lista_t));
    assert(l != NULL);

    l->senti = NULL;
    l->tam = 0;

    return l;
}

void liberar(lista_t *l){
    if(l != NULL){
        no_t *p, *aux;
       if(l->senti == NULL){
           free(l);
           return;
       }
       p = l->senti->prox;
       while(p != l->senti){
           aux = p;
           p = p->prox;
           free(aux);
       }
        free(l->senti);
        free(l);
    }
}

int inserir(lista_t *l, elem x){
    assert(l != NULL);
    
    if(esta_na_lista(l, x) == 1){
        return 1;
    } // não insere elem repetidos

    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->info = x;
    if(l->senti == NULL){
        p->prox = p; // aponta "p ele mesmo"
    }
    else{
        p->prox = l->senti->prox;
        l->senti->prox = p;
    }
    l->senti = p;        
    l->tam++;
    return 1;
}

int tamanho(lista_t *l){
    assert(l != NULL);
    return l->tam;
}

void imprimir(lista_t *l){
    assert(l != NULL);

    no_t *p;
    if(l->senti == NULL) return;

    p = l->senti->prox;

    do{
        printf("%d ", p->info);
        p = p->prox;
    }while(p != l->senti->prox); // imprime os elem enqto nao volta nele mesmo
    printf("\n");
}

int esta_na_lista(lista_t *l, elem x){
    assert(l != NULL);
    no_t *p;
    if(l->senti == NULL){
        return 0;
    }
    p = l->senti;
    do{
        if(p->info == x){
            return 1;
        }
        p = p->prox;
    }while(p != l->senti);
    return 0;
}

int remover(lista_t *l, elem x){
    assert(l != NULL);
    
    no_t *ant, *atual;
    
    if(l->senti == NULL)
        return 0;

    ant = l->senti;
    atual = l->senti->prox;
    do{
        if(x == atual->info){
            ant->prox = atual->prox;
            if(atual == l->senti){
                l->senti = ant;
            }
            if(atual == ant){
                l->senti = NULL;
            }
            free(atual);
            l->tam--;
            return 1;
        }
        ant = atual;
        atual = atual->prox;
    }while(atual != l->senti->prox);
    return 0;
}
