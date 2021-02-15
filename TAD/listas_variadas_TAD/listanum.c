#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"listanum.h"

typedef struct no no_t;

struct no{
    elem info;
    no_t *prox, *ant;
};

struct lista{
    no_t *ini, *fim;
    int tam;
};

lista_t *cria(){
    lista_t *l;
    l = (lista_t *)malloc(sizeof(lista_t));
    assert(l != NULL);

    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;

    return l;
}

void liberar(lista_t *l){
    if(l != NULL){
        no_t *p = l->ini;
        while(p != NULL){
            l->ini = p->prox;
            free(p);
            p = l->ini;
        }
        free(l);
    }
}

void inserir(lista_t *l, elem x){
    assert(l != NULL);

    no_t *p = (no_t *)malloc(sizeof(no_t));
    p->info = x;
    p->prox = NULL;
    p->ant = NULL;

    // 1º caso lista vazia
    if(l->ini == NULL){
        l->ini = p;
    }
    else{ // 2º caso lista com pelo menos um elem
        l->fim->prox = p;
        p->ant = l->fim;
        l->fim = p;
    }
    l->fim = p;

    l->tam++;
   
}

int big(lista_t *l1, lista_t *l2){
    assert(l1 != NULL);
    assert(l2 != NULL);

    no_t *p1 = l1->ini;
    no_t *p2 = l2->ini;
    int cont = 0;

    while(p1 != NULL && p2 != NULL){
        
        if(p1->info > p2->info){
            cont = 1;
        }else if(p1->info <= p2->info){
            cont = 0;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }
    if(p1 != NULL){
        return 1;
    }else if (p2 != NULL){
      if(p2->info < 0){
        return 1;
      }else if (p2->info > 0){
        return 0;
      }
    }
    if(cont == 1){
      return 1;
    }else{
      return 0;
    }
    
}

int sml(lista_t *l1, lista_t *l2){
    assert(l1 != NULL);
    assert(l2 != NULL);

    no_t *p1 = l1->ini;
    no_t *p2 = l2->ini;
    int cont = 0;
    while(p1 != NULL && p2 != NULL){
        
       if(p1->info < p2->info){
            cont = 1;
        }else if(p1->info >= p2->info){
            cont = 0;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }
    if(p1 != NULL){
        return 0;
    }else if (p2 != NULL){
      if(p2->info < 0){
        return 0;
      }else{
        return 1;
      }
    }
    if(cont == 1){
      return 1;
    }else{
      return 0;
    }

}

int eql(lista_t *l1, lista_t *l2){
    assert(l1 != NULL);
    assert(l2 != NULL);
    int cont = 0;

    no_t *p1 = l1->ini;
    no_t *p2 = l2->ini;
    while(p1 != NULL && p2 != NULL){
        if(p1->info != p2->info){
            return 0;
        }
        p1 = p1->prox;
        p2 = p2->prox;
        cont++;
    }

    if(cont == l1->tam && cont == l2->tam){
        return 1;
    }
    return 0;
}

void imprimir_inv(lista_t *l){
    assert(l != NULL);

    while(l->fim->info == 0){
        l->fim = l->fim->ant;
    }
    no_t *p = l->fim;
    while(p != NULL){
        printf("%d", p->info);
        p = p->ant;
    }
}

void soma(lista_t *l1, lista_t *l2){

    assert(l1 != NULL);
    assert(l2 != NULL);

    lista_t *soma = cria();

    int res;
    int carry = 0; 
    no_t *p1 = l1->fim;
    no_t *p2 = l2->fim;

    
    while(p1 != NULL && p2 != NULL){   

        res = p1->info + p2->info + carry;
  
        if(res <= 9){
           inserir(soma, res);
            carry = 0;
        }
        else{
            res = res%10;
            inserir(soma, res);    
            carry = 1;   
        }
        p1 = p1->ant;
        p2 = p2->ant;
    }
    if(carry == 1 && l1->tam == l2->tam){
        inserir(soma, carry);
    }
    
    int dif = l1->tam - l2->tam;

    if(dif > 0){
        while(p1 != NULL){
            if(carry == 0){    
           inserir(soma, p1->info);
    
            }
        else if(carry == 1){
                int res = p1->info +1;
                if(res <= 9){
                    inserir(soma, res);
                    carry = 0;
                }else{
                    res = res%10;
                    inserir(soma, res);    
                    carry = 1;   
        }
            }
        p1 = p1->ant;
        }
    } else if(dif < 0){
        while(p2 != NULL){
            if(carry == 0){    
           inserir(soma, p2->info);
            }
        else if(carry == 1){
                int res = p2->info +1;
                if(res <= 9){
                    inserir(soma, res);
                    carry = 0;
                }else{
                    res = res%10;
                    inserir(soma, res);    
                    carry = 1;   
        }
            }
        p2 = p2->ant;
        }
    }

    if(carry == 1 && l1->tam != l2->tam){
        inserir(soma, carry);
    }
    imprimir_inv(soma);
}