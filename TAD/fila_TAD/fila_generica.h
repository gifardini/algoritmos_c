#ifndef FILA_GENERICA_H_INCLUDED
#define FILA_GENERICA_H_INCLUDED

#define tam_fila 100

typedef struct fila fila_t;
typedef int elem;

fila_t *criar(int tamElem);
int isEmpty(fila_t *f);
int isFull(fila_t *f);
int inserir(fila_t *f, void *x);
int remover(fila_t *f, void *x); // vai ser alterado deve ser por ref
void destruir(fila_t *f);
#endif // FILA_GENERICA_H_INCLUDED