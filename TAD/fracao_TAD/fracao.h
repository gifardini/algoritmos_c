#ifndef FRACAO_H_INCLUDED
#define FRACAO_H_INCLUDED

typedef struct{
int num, den;
}fracao_t;

fracao_t *criar(int num, int den);
void imprimir(fracao_t *f);
void destruir(fracao_t *f);
fracao_t *soma(fracao_t *f1, fracao_t *f2);
fracao_t *subtr(fracao_t *f1, fracao_t *f2);
fracao_t *multip(fracao_t *f1, fracao_t *f2);
fracao_t *divisao(fracao_t *f1, fracao_t *f2);


#endif // FRACAO_H_INCLUDED
