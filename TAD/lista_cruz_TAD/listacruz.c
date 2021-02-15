#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"listacruz.h"

typedef struct no no_t;
typedef struct matriz matriz_t;

struct no{
    int lin, col, val;
    no_t *pcol, *plin;
};
struct  matriz{
    no_t **lin, **col;
    int  nlin, ncol;
};

matriz_t *criar(int nlinhas, int ncolunas){
    matriz_t *m = (matriz_t *)malloc(sizeof(no_t *)*nlinhas);
    m->nlin = nlinhas;
    m->ncol = ncolunas;

    m->lin = (no_t **)malloc(sizeof(no_t *)*nlinhas);
    m->col = (no_t **)malloc(sizeof(no_t *)*ncolunas);
    for(int i = 0; i < nlinhas; i++){
        m->lin[i] = NULL;
    }
    for(int i = 0; i < ncolunas; i++){
        m->col[i] = NULL;
    }
    return m;
}

//pode repetir valores
void insere(matriz_t *m, int linha, int coluna, int val){
    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->lin = linha;
    p->col = coluna;
    p->val = val;
    p->pcol = NULL;
    p->plin = NULL;

    no_t *aux = m->lin[linha];
    no_t *ant = NULL;
    while(aux != NULL && aux->col < coluna){
        ant = aux;
        aux = aux->pcol;
    }
    if(ant == NULL){ //inicio da lista
        if(aux != NULL){ // tem pelo menos 1 elem
            p->pcol = aux;
        }
        m->lin[linha] = p;
    }else{ // meio ou fim 
        ant->pcol = p;
        p->pcol = aux;
    }
    aux = m->col[coluna];
    ant = NULL;
    while(aux != NULL && aux->lin < linha){
        ant = aux;
        aux = aux->plin;
    }
    if(ant == NULL){
        if(aux != NULL){
            p->plin = aux;
        }
        m->col[coluna] = p;
    } else{
        ant->plin = p;
        p->plin = aux;
    }
}
void imprime(matriz_t *m){
    for(int i = 0; i < m->nlin; i++){
        no_t *aux = m->lin[i];
        while(aux != NULL){
            printf("%d %d %d\n", aux->lin, aux->col, aux->val);
            aux = aux->pcol;
        }
    }
}
void imprime_completa(matriz_t *m){
    for(int i = 0; i < m->nlin; i++){
        no_t *aux = m->lin[i];
        for(int j = 0; j < m->ncol; j++){
            if(aux == NULL){
                printf("0");
            }else if(aux->col == j){
                printf("%d", aux->val);
                aux = aux->pcol;
            }else{
                printf("0");
            }
            if(j < m->ncol - 1) printf("\t");
        }
        printf("\n");
    }
}

void liberar(matriz_t *m){
    no_t *aux2;
    for(int i = 0; i < m->nlin; i++){
        no_t *aux = m->lin[i];
        while(aux != NULL){
            aux2 = aux;
            aux = aux->pcol;
            free(aux2);
        }
    }
    free(m->lin);
    free(m->col);
    free(m);
}
void remover(matriz_t *m, int linha, int coluna){
    no_t *aux = m->lin[linha];
    no_t *ant = NULL;
    while(aux != NULL && aux->col != coluna){
        ant = aux;
        aux = aux->pcol;
    }
    if(aux == NULL){
        return;
    }
    if(ant == NULL){
        m->lin[linha] = aux->pcol;
    }else{
        ant->pcol = aux->pcol;
    }
    aux = m->col[coluna];
    ant = NULL;

    while(aux != NULL && aux->lin != linha){
        ant = aux;
        aux = aux->plin;
    }
    if(aux == NULL){
        return;
    }
    if(ant == NULL){
        m->col[coluna] = aux->plin;
    }else{
        ant->plin = aux->plin;
    }
    free(aux);
}
void soma(matriz_t *m, int linha, int coluna, int val){
    no_t *aux = m->lin[linha];
    if(aux == NULL){
        insere(m, linha, coluna, val);
        return;
    }
    while(aux != NULL){
       if(coluna == aux->col){
           aux->val += val;
           if(aux->val == 0){
               remover(m, linha, coluna);
           }
           return;
       }
       if(coluna < aux->col){
           insere(m, linha, coluna, val);
           return;
       } 
       aux = aux->pcol;
    }
    insere(m, linha, coluna, val);
}
void soma_linha(matriz_t *m, int linha, int val){
    for(int i = 0; i < m->ncol; i++){
        soma(m, linha, i, val);
    }
}
void soma_coluna(matriz_t *m, int coluna, int val){
    for(int i = 0; i < m->nlin; i++){
        soma(m, coluna, i, val);
    }
}