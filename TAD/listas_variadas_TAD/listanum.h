typedef int elem;
typedef struct lista lista_t;

lista_t *cria();
void liberar(lista_t *l);
void inserir(lista_t *l, elem x);
void imprimir(lista_t *l);
int big(lista_t *l1, lista_t *l2);
int sml(lista_t *l1, lista_t *l2);
int eql(lista_t *l1, lista_t *l2);
void soma(lista_t *l1, lista_t *l2);
void insere_zero(lista_t *l);