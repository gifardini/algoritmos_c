#include <stdio.h>
#include <stdlib.h>

void radix_sort(int b, int n, unsigned int v[]);
void counting_sort(int base, int exp, int size, unsigned int v[]);

int main(void) {
    int b, n, i;
    unsigned int *v;

    scanf("%d", &b);
    scanf("%d", &n);

    v = (unsigned int *) malloc(sizeof(unsigned int) * n);
    for (i = 0; i < n; i++)
        scanf("%u", &v[i]);

    radix_sort(b, n, v);

    free(v);
    return 0;
}

void counting_sort(int base, int exp, int size, unsigned int v[]) {
    int i, j;
    int *count, *aux_v;

    count = (int *) calloc(base, sizeof(int));
    aux_v = (int *) calloc(size, sizeof(unsigned int));

    for (i = 0; i < size; i++) {
        int d = (v[i]/exp) % base;
        count[d] += 1;
    }

    j = 0;
    for (i = 0; i < base; i++) {
        int aux = count[i];
        count[i] = j;
        j += aux;
    }

    for (i = 0; i < size; i++) {
        int d = (v[i]/exp) % base;
        aux_v[count[d]] = v[i];
        count[d] += 1;
    }

    for (i = 0; i < size; i++) {
        v[i] = aux_v[i];
    }

    free(count);
    free(aux_v);
}

void radix_sort(int b, int n, unsigned int v[]) {
    int i, m, j;

    m = v[0];

    // busca o maior elemento do vetor
    for (i = 1; i < n; i++) {
        if (v[i] > m)
            m = v[i];
    }

    for (int i = 1; m / i > 0; i *= b) {
        counting_sort(b, i, n, v);
        for (j = 0; j < n; j++)
            printf("%u ", v[j]);
        printf("\n");
    }
}
