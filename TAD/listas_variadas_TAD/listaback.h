typedef int elem;
typedef struct lista lista_t;

lista_t *criar();
int inserir(lista_t *l, elem c, elem back);
int remover(lista_t *l, elem c);
void imprimir(lista_t *l);
void liberar(lista_t *l);