#ifndef PILHA_GENERICA_H_INCLUDED
#define PILHA_GENERICA_H_INCLUDED

#define tampilha 100
typedef int elem;
typedef struct pilha pilha_t;

pilha_t *create (int tamElem);
void destroy(pilha_t *p);
int isFull(pilha_t *p);
int isEmpty (pilha_t *p);
int push(pilha_t *p, void *x);
int pop(pilha_t *p, void *x);
int top(pilha_t *p, void *x);

#endif // PILHA_GENERICA_H_INCLUDED
