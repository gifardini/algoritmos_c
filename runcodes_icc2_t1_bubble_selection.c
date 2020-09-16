#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void Troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection(int *v, int n) {
  int i,j;
    for (i = 0; i < n-1; i++) {
        int minimo = i;
        for (j = i + 1; j < n; j++) {
            printf("C %d %d\n", minimo, j);
            if (v[j] < v[minimo])
                minimo = j;
        }
    if(minimo != i){
    printf("T %d %d\n", i, minimo);
    Troca(&v[minimo], &v[i]);
    }
  }
}

void bubble_sent(int *v, int n){

    int k, s, aux = 0;

    for (s = n - 1; s >= 1; s--) {
        for(k = 0; k < s; k++){
            printf("C %d %d\n", k, k+1);
            if (v[k] > v[k + 1]) {
               Troca(&v[k], &v[k+1]);
                printf("T %d %d\n", k, k+1);
                aux = 1;
                }
            }
           if(aux == 0) break;
           aux = 0;
        }
}

int main(){
    int *v, i, n_vetor;
    char metodo[10];

    fgets(metodo, 10, stdin);
    scanf("%d", &n_vetor);

    v = (int *)calloc(n_vetor, sizeof(int));
    assert(v != NULL);

    for (i = 0; i < n_vetor; i++) {
        scanf("%d", &v[i]);
    }

    if(strstr(metodo, "selecao")){
        selection(v, n_vetor);
    }

    else if(strstr(metodo, "bolha")){
        bubble_sent(v, n_vetor);
    }

    for (i = 0; i < n_vetor; i++) {
        printf("%d ",v[i]);
    }

    return 0;
}