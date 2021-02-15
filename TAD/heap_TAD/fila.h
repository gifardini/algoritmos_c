#define MAX 100

typedef struct fila fila_t;
typedef int elem;
typedef struct no no_t;

fila_t *criar();
int isEmpty(fila_t *f);
int isFull(fila_t *f);
void destruir(fila_t *f);
int inserir(fila_t *f, elem chave, int prio);
int remover(fila_t *f, elem *chave);


