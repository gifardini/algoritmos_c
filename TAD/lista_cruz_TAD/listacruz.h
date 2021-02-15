typedef struct no no_t;
typedef struct matriz matriz_t;

matriz_t *criar(int nlinhas, int ncolunas);
void insere(matriz_t *m, int linha, int coluna, int val);
void imprime(matriz_t *m);
void imprime_completa(matriz_t *m);
void soma(matriz_t *m, int linha, int coluna, int val);
void soma_linha(matriz_t *m, int linha, int val);
void soma_coluna(matriz_t *m, int coluna, int val);
void liberar(matriz_t *m);
void remover(matriz_t *m, int linha, int coluna);