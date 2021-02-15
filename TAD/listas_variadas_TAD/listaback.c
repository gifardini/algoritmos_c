#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"listaback.h"

typedef struct no no_t;

struct no{
    elem chave, tempo;
    no_t *ant, *prox;
};

struct lista{
    no_t *inicio, *fim;
    int tam, time;
};

lista_t *criar(){
    lista_t *p;
    p = (lista_t *)malloc(sizeof(lista_t));
    p->inicio = NULL;
    p->fim = NULL;
    p->tam = 0;
    p->time = 0;

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

int inserir(lista_t *l, elem c, elem back){
    assert(l != NULL);

    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->chave = c;
    p->prox = NULL;
    p->tempo = l->time;

   if(l->inicio == NULL){
       l->inicio = p;
   }else{
       l->fim->prox = p;
   }
   l->fim = p;

    if(back == 0){
        p->ant = NULL;
    }else{
        
        no_t *aux;
        int pos = l->tam - back;
        int i;
        aux = l->inicio;
        for(i = 0; i < pos; i++){
            aux = aux->prox;
        }
        if(i == pos){
            p->ant = aux;
        }

    }
    l->time++;
    l->tam++;
    return 1;

}


int remover(lista_t *l, elem c){
    assert(l != NULL);
    
    no_t *aux, *back;
    no_t *p = l->inicio;
    
    while (p != NULL){
        
        if(p->chave == c){
            // 1º caso: rem do inicio
            if(p == l->inicio){
                l->inicio = l->inicio->prox;
                free(p); 
            }
            else if(p == l->fim){ // rem do fim
            l->fim = aux;
            l->fim->prox = NULL;
            free(p);
            }
            else{ // rem do meio
                aux->prox = p->prox;
                free(p);
            }

            no_t *k;
            k = l->inicio;

            while(k != NULL){
                if(k->ant == p){
                    k->ant = NULL;
                }
                else{
                    k = k->prox;
                }
            }        
            l->tam--;
            l->time++;  
            return 1;
        }
        else{
            aux = p;
            p = p->prox;
        }   
    }   
    return 0;
}

void imprimir(lista_t *l){
    no_t *p = l->inicio;

    if(l->inicio == NULL){
        printf("-1");
    }
    
    while(p != NULL){
        if(p->ant == NULL){
            printf("[%d,%d] ", p->chave, p->tempo);
        }
        else if(p->ant != NULL){
            no_t *aux = l->inicio;
            int i = 0;
            while(aux != p){
                if(aux == p->ant){
                    break;
                }
                aux = aux->prox;
                i++;
            }
            printf("[%d,%d,%d] ", p->chave, p->tempo, i);
        }
        
        p = p->prox;
    }
    printf("\n");
}
