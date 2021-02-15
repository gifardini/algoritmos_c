typedef int elem;
typedef struct no no_t;

typedef struct arvore{
    no_t *raiz;
}arvore_t;

arvore_t *criar();
int esta_vazia(arvore_t *a);
void finalizar(no_t *raiz);
void imprimir(no_t *raiz);
int altura(no_t *raiz);
no_t *busca(no_t *raiz, elem x);
void inserir(arvore_t *a, elem x);
void remover(arvore_t *a, elem x);
void pre_ordem(no_t *raiz);
void em_ordem(no_t *raiz);
void pos_ordem(no_t *raiz);
no_t *insere_avl(no_t *raiz, elem x, int *flag);
no_t *remove_avl(no_t *raiz, elem x, int *h);
no_t *rotacao_ee(no_t *desb);
no_t *rotacao_ed(no_t *desb);
no_t *rotacao_de(no_t *desb);
no_t *rotacao_dd(no_t *desb);
no_t *balanceamento_direito(no_t *p, int *h);
no_t *balanceamento_esquerdo(no_t *p, int *h);
no_t *busca_remove(no_t *p, no_t *no_chave, int *h);
