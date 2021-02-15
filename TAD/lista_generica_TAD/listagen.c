#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"listagen.h"

void libera(no_t *p){
    no_t *aux;

    while(p != NULL){
        if(p->tipo == 1){
            libera(p->info.sublista);
        }
        aux = p;
        p = p->prox;
        free(aux);
    }
}

no_t *atomo(elem x){
    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->tipo = 0;
    p->prox = NULL;
    p->info.atomo = x;
    return p;
}

no_t *sublista(no_t *sublista){
    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->tipo = 1;
    p->prox = NULL;
    p->info.sublista = sublista;
    return p;
}

no_t *concat(no_t *p, no_t *q){
    assert(p != NULL);
    p->prox = q;
    return p;
}

info_t cabeca(no_t *p, int *tipo){
    assert(p != NULL);
    *tipo = p->tipo;
    return p->info;
}

no_t *cauda(no_t *p){
    assert(p != NULL);
    return p->prox;
}

void imprime(no_t *p){
    if(p == NULL)
        return;
    
    printf("(");
    while(p != NULL){
        if(p->tipo == 0){
            printf("%d", p->info.atomo);
        } else{
            imprime(p->info.sublista);
        }
        if(p->prox != NULL){
            printf(", ");
        }
        p = p->prox;
    }
    printf(")");
}

void imprimir(no_t *p){
    imprime(p);
    printf("\n");
}

int esta_na_lista(no_t *p, elem x){
    assert(p != NULL);

    while(p != NULL){
        if(p->tipo == 0){
            if(x == p->info.atomo){
                return 1;
            } 
        } else{
            if(esta_na_lista(p->info.sublista, x)){
                return 1;
            }
        }             
        p = p->prox;   
    }
    return 0;
}

int compara_listas(no_t *p, no_t *q){
    assert(p != NULL && q != NULL);
    int aux = 0;

    while(p != NULL && q != NULL){
        if(p->tipo == 0 && q->tipo == 0){
            if(p->info.atomo == q->info.atomo){
                aux = 1;
            }
        } else if(p->tipo == 1 && q->tipo == 1){
            if(compara_listas(p->info.sublista, q->info.sublista)){
                aux = 1;
            }
        } else{
            aux = 0;
        }
        p = p->prox;
        q = q->prox;
    }
    if(aux == 1)
        return 1;
    else 
        return 0;

}

int profundidade(no_t *p){
    if(p == NULL){
        int prof = 0;
        return prof;
    }

    int prof = 1;
    while(p != NULL){
        if(p->tipo == 1){
            prof++;
            profundidade(p->info.sublista);
        }
        p = p->prox;
    }
    return prof;
}