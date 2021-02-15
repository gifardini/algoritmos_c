#include "polinomio.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

typedef union{
    char atomo;
    no_t *sublista;
} var_t;

struct no{
    int tipo;
    int val;
    var_t var;
    no_t *prox;
};

struct poli{
    no_t *inicio, *fim;
};

poli_t *criar(){
    poli_t *p = (poli_t *)malloc(sizeof(poli_t));
    p->inicio = NULL;
    p->fim = NULL;
    return p;
}

void libera(no_t *p){
    no_t *aux;

    while(p != NULL){
        if(p->tipo == 1)
            libera(p->var.sublista);
        aux = p;
        p = p->prox;
        free(aux);
    }
}

void liberar(poli_t *p){
    libera(p->inicio);
}

void imprimir(poli_t *poli){
    no_t *aux, *p;
    assert(poli != NULL);
    p = poli->inicio;
    if(p == NULL){
        return;
    }
    while(p != NULL){
        printf("%d", p->val);
        aux = p->var.sublista;
        while(aux != NULL){
            printf("%c^%d", aux->var.atomo, aux->val);
            aux = aux->prox;
        }
        p = p->prox;
        if(p != NULL && p->val >= 0){
            printf("+");
        }
    }
    printf("\n");
}

void add_term(poli_t *poli, int coef, char *vars, int *exps){
    no_t *aux, *fim;
    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->tipo = 1;
    p->val = coef;
    p->prox = NULL;
    for(int i = 0; i < strlen(vars); i++){
        aux = (no_t *)malloc(sizeof(no_t));
        aux->tipo = 0;
        aux->var.atomo = vars[i];
        aux->val = exps[i];
        aux->prox = NULL;
        if(i == 0){
            p->var.sublista = aux;
        }
        else{
            fim->prox = aux;
        }
        fim = aux;
    }
    if(poli->inicio == NULL){
        poli->inicio = p;
    } else{
        poli->fim->prox = p;
    }
    poli->fim = p;
}

int calcula_xyz(poli_t *poli, int x, int y, int z){
 no_t *p, *aux;
 int total = 0;

 assert(poli != NULL);
 p = poli->inicio;
 if(p == NULL){
     return 0;
 }   

 while(p != NULL){
     aux = p->var.sublista;
     int parcial = p->val;
     while(aux != NULL){
         switch (aux->var.atomo){
         case 'x': parcial *= pow(x, aux->val); break;
         case 'y': parcial *= pow(y, aux->val); break;
         case 'z': parcial *= pow(z, aux->val); break;
         }
         aux = aux->prox;
     }
     total += parcial;
     p = p->prox;
 }
 return total;
}