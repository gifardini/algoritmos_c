#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define tam_fila 100

typedef struct fila fila_t;
typedef int elem;
fila_t *criar();
int isEmpty(fila_t *f);
int isFull(fila_t *f);
int inserir(fila_t *f, elem x);
int remover(fila_t *f, elem *x); // vai ser alterado deve ser por ref
void destruir(fila_t *f);
#endif // FILA_H_INCLUDED
