#ifndef PILHA_GENERICA_H_INCLUDED
#define PILHA_GENERICA_H_INCLUDED

#define tampilha_max 100000
typedef struct pilha pilha_t;

pilha_t *create (int tamElem, int tampilha);
void destroy(pilha_t *p);
int isFull(pilha_t *p, int tampilha);
int isEmpty (pilha_t *p);
int push(pilha_t *p, void *x, int tampilha);
int pop(pilha_t *p, void *x);
int top(pilha_t *p, void *x);

#endif // PILHA_GENERICA_H_INCLUDED
