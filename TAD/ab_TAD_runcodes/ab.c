#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"ab.h"

struct no{
    no_t *esq, *dir;
    elem info;
};

arvore_t *criar(){
    arvore_t *a = (arvore_t *)malloc(sizeof(arvore_t));
    a->raiz = NULL;
    return a;
}
int esta_vazia(arvore_t *a){
    assert(a != NULL);
    if(a->raiz == NULL){
        return 1;
    }
    return 0;
}
void finalizar(no_t *raiz){
    if(raiz != NULL){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}
void imprimir(no_t *raiz){
    if(raiz != NULL){
        printf("%d(", raiz->info);
        imprimir(raiz->esq);
        printf(",");
        imprimir(raiz->dir);
        printf(")");
    }else{
        printf("null");
    }
}

void imprimir_elem(no_t *raiz, elem pai){
        
    if(raiz != NULL){
        printf("no %d: pai = %d, altura = %d, grau = %d, filhos = (", raiz->info, pai, altura(raiz), grau(raiz));
        if(raiz->esq != NULL){
            printf("%d,", raiz->esq->info);
        }else if(raiz->esq == NULL){
            printf("-1,");
        }
        
        if(raiz->dir != NULL){
            printf("%d), tipo = ", raiz->dir->info);
        }else if(raiz->dir == NULL){
            printf("-1), tipo = ");
        }

        if(pai == -1){
            printf("raiz\n");
        }else if(pai != -1 && grau(raiz) != 0){
            printf("interno\n");
        }else if(altura(raiz) == 1){
            printf("folha\n");
        }
        imprimir_elem(raiz->esq, raiz->info);
        imprimir_elem(raiz->dir, raiz->info);
    }
}

int grau (no_t *raiz){
    if(raiz == NULL){
        return 0;
    }
    int grau = 0;
    if(raiz->esq != NULL)
        grau++;
    if(raiz->dir != NULL)
        grau++;

    return grau;
}   

int altura(no_t *raiz){
    if(raiz == NULL){
        return 0;
    }
    int alt_esq = 1 + altura(raiz->esq);
    int alt_dir = 1 + altura(raiz->dir);

    if(alt_esq > alt_dir){
        return alt_esq;
    }else{
        return alt_dir;
    }
}
no_t *busca(no_t *raiz, elem x){
    if(raiz == NULL)
        return NULL;

    if(raiz->info == x){
        return raiz;
    }
    no_t *p = busca(raiz->esq, x);
    if(p == NULL){
        p = busca(raiz->dir, x);
    }
    return p;
}
no_t *busca_pai(no_t *raiz, elem x){
    if(raiz == NULL)
        return NULL;

    if(raiz->esq != NULL && raiz->esq->info == x){
        return raiz;
    }    
    if(raiz->dir != NULL && raiz->dir->info == x){
        return raiz;
    }
    no_t *p = busca_pai(raiz->esq, x);
    if(p == NULL){
        p = busca_pai(raiz->dir, x);
    }
    return p;
}

// se pai == -1 insere na raiz
// caso contrário insere no filho esquerdo
int inserir_esq(arvore_t *a, elem x, elem pai){
        if(x == -1){
        return 0; 
    }
    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->esq = NULL;
    p->dir = NULL;
    p->info = x;
        if(pai == -1){
            if(a->raiz == NULL){
                a->raiz = p;
            }else{
                free(p);
                return 0;
            }
        }else{
            no_t *aux = busca(a->raiz, pai);
            if(aux != NULL && aux->esq == NULL){
                aux->esq = p;
            }else{
                free(p);
                return 0;
            }
        }
        return 1;
}

int inserir_dir(arvore_t *a, elem x, elem pai){
        if(x == -1){
        return 0; 
    }
    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->esq = NULL;
    p->dir = NULL;
    p->info = x;
        if(pai == -1){
            if(a->raiz == NULL){
                a->raiz = p;
            }else{
                free(p);
                return 0;
            }
        }else{
            no_t *aux = busca(a->raiz, pai);
            if(aux != NULL && aux->dir == NULL){
                aux->dir = p;
            }else{
                free(p);
                return 0;
            }
        }
        return 1;
}
int remover(arvore_t *a, elem x) {
    no_t *p, *pai;
    int eh_esq;

    //1a etapa: setar p e pai
    if(a->raiz != NULL && a->raiz->info == x) {
        p = a->raiz;
        pai = NULL;
    }
    else {
        pai = busca_pai(a->raiz, x);
        if(pai != NULL) {
            if(pai->esq != NULL && pai->esq->info == x) {
                p = pai->esq;
                eh_esq = 1;
            }
            else {
                p = pai->dir;
                eh_esq = 0;
            }
        }
        else { // pai eh NULL -> elemento procurado não existe
            p = NULL;
        }
    }

    //2a etapa: fazer a remocao de p
    if(p == NULL) {
        return 0;
    }
    else {
        if(p->esq == NULL && p->dir == NULL) { // remoção de p como folha
            if(pai == NULL) {
                a->raiz = NULL;
            }
            else {
                if(eh_esq == 1) {
                    pai->esq = NULL;
                }
                else {
                    pai->dir = NULL;
                }
            }
            free(p);
            return 1;
        }
        else { // ou esq existe e/ou dir existe
            if(p->esq != NULL) {
                p->info = p->esq->info;
                p->esq->info = x;
            }
            else {
                p->info = p->dir->info;
                p->dir->info = x;
            }
            return remover(a, x);
        }
    }
}

void pre_ordem(no_t *raiz){
    if(raiz != NULL){
        printf("%d", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
void em_ordem(no_t *raiz){
    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf("%d", raiz->info);
        em_ordem(raiz->dir);
    }
}
void pos_ordem(no_t *raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d", raiz->info);
    }
}