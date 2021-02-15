#include <stdio.h>
#include <stdlib.h>

void sort_counting(int k, int n, int v[]);

int main(void) {
    int k, n, i;
    int *v;

    scanf("%d", &k);
    scanf("%d", &n);

    v = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    sort_counting(k, n, v);
    
    free(v);
    return 0;
}

void sort_counting(int k, int n, int v[]) {
    int i, j;
    int *aux_k, *aux_v;

    aux_k = (int *) calloc(k, sizeof(int)); // Conta as aparições de cada valor
    aux_v = (int *) calloc(n, sizeof(int)); // Vetor auxiliar para guardar os elementos ordenados

    for (i = 0; i < n; i++) {
        aux_k[v[i]] += 1;
    }

    // Os valores em aux_k devem apontar para a primeira
    // posição que cada valor ocupa.
    j = 0;
    for (i = 0; i < k; i++) {
        int aux = aux_k[i];
        aux_k[i] = j;
        j += aux;
    }

    for (i = 0; i < n; i++) {
        printf("%d %d\n", v[i], aux_k[v[i]]);
        aux_v[aux_k[v[i]]] = v[i];
        aux_k[v[i]] += 1;
    }

    for (i = 0; i < n; i++)
        v[i] = aux_v[i];

    free(aux_k);
    free(aux_v);
}
