typedef struct no no_t;
typedef struct poli poli_t;

poli_t *criar();
void liberar(poli_t *p);
void libera(no_t *p);
void imprimir(poli_t *p);
void add_term(poli_t *poli, int coef, char *vars, int *exps);
int calcula_xyz(poli_t *poli, int x, int y, int z);
