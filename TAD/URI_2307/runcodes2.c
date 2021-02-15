#include<stdio.h>
#include<stdlib.h>
#include"pilha_generica.h"

int main (){

pilha_t *compra, *morto, *descarte, *aux;

int N;
scanf("%d", &N);

compra = create(sizeof(int), N);
morto = create(sizeof(int), N);
descarte = create(sizeof(int), N);
aux = create(sizeof(int), N);
int carta;

    for(int i = 1; i <= N; i++){
        scanf("%d", &carta);
        push(aux, &carta, N);
    }
    while(!isEmpty(aux)){
        pop(aux, &carta);
        push(compra, &carta, N);
    }
    
    int j = 1, rodada = 0;
    int i = 1;

    while(!isFull(morto, N)){
        i = j;
        while(!isEmpty(compra)){
            pop(compra, &carta);
            if(carta == i){
                push(morto, &carta, N);
                i++;
                j++;
            }
            else{
                push(descarte, &carta, N);
            }
            
        }
        rodada++;

        while(!isEmpty(descarte)){
            pop(descarte, &carta);
            push(compra, &carta, N);
        }
    }
    
    printf("%d\n", rodada);

    destroy(compra);
    destroy(morto);
    destroy(descarte);
    destroy(aux);   
    return 0;
}