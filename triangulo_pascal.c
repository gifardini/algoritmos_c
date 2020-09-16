#include <stdio.h>
#include <stdlib.h>

void calcular_matriz(int , int **);
void imprimir_matriz(int , int **);

int main(){
  int n, i, j, **T;

  printf("Digite o numero de linhas do Triangulo de Pascal:  ");
  scanf("%d", &n);

  T = (int **) malloc((n+1)*sizeof(int *));
  if (T == NULL) {
    printf("Erro memoria insuficiente. \n");
    return NULL;
  }

  for(i=0; i<(n+1); i++) {
    T[i] = (int *) malloc((i+1)*sizeof(int));

    if (T[i] == NULL) {
      printf("Erro memoria insuficiente. \n");
    return NULL;
    }
  }

  if (n<0){
    return 0;
  }

  calcular_matriz(n,T);
  imprimir_matriz(n,T);

  return(0);
}

void calcular_matriz(int n, int **T) {

  int i, j;

  T[0][0] = 1;
  for (i=0; i<(n+1); i++) {
    T[i][0] = 1;
    T[i][i] = 1;
    for (j = 1; j < i; j++) {
      T[i][j] = T[i-1][j] + T[i-1][j-1];
    }
  }
}

void imprimir_matriz(int n, int **T) {
  int i, j;

  for (i=0; i<(n+1); i++) {
    for (j = 0; j <= i; j++) {
      printf("%5d ", T[i][j]);
    }
    printf("\n");
  }
}
