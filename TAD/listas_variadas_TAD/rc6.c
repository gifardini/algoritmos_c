#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"listanum.h"
#include<string.h>

int main(){

    int N;
    scanf("%d", &N);
    char cmd[10] = {0};
    char num1[50], num2[50];

    for(int i = 1; i <= N; i++){
        scanf("%s", cmd);
        scanf("%s", num1);
        scanf("%s", num2);
        lista_t *l1 = cria();
        lista_t *l2 = cria();
        int tam_n1 = strlen(num1);
        int tam_n2 = strlen(num2);
        for(int j = 0; j < tam_n1; j++){
            char letra[2];
            int aux;
            if(num1[0] == '-'){
                letra[0] = num1[j+1];
                aux = atoi(letra);
                aux *= -1;
                inserir(l1, aux);
                tam_n1 = strlen(num1) - 1;
                
            }else{
                letra[0] = num1[j];
                aux = atoi(letra);
                inserir(l1, aux);
                
            }

        }
      
        for(int j = 0; j < tam_n2; j++){
            char letra[2];
            int aux;
            if(num2[0] == '-'){
                letra[0] = num2[j+1];
                aux = atoi(letra);
                aux *= -1;
                inserir(l2, aux);
                tam_n2 = strlen(num2) - 1;
            }else{
                letra[0] = num2[j];
                aux = atoi(letra);
                inserir(l2, aux);
                
            }
        }
        if(!strcmp(cmd, "sum")){
         printf("Resultado %d: ", i);
         soma(l1, l2);
         printf("\n"); 

        }else if(!strcmp(cmd, "big")){
          if(big(l1, l2)){
            printf("Resultado %d: 1\n", i);
          } else{
            printf("Resultado %d: 0\n", i);
          }
        }else if(!strcmp(cmd, "sml")){
            if(sml(l1, l2)){
            printf("Resultado %d: 1\n", i);
          } else{
            printf("Resultado %d: 0\n", i);
          }
        }else{
          if(eql(l1, l2)){
            printf("Resultado %d: 1\n", i);
          } else{
            printf("Resultado %d: 0\n", i);
          }
        }
        liberar(l1);
        liberar(l2);
    }
    return 0;
}