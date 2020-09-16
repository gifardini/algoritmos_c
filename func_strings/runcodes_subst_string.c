#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void substitui(char *s, char *erro, char *correcao){

    char *str_corrigida;
    int i, tam_correcao = strlen(correcao), tam_erro = strlen(erro);

    str_corrigida = (char *)malloc(MAX*sizeof(char));

    i = 0;
    while(*s){
        if(strstr(s, erro) == s){
            strcpy(&str_corrigida[i], correcao); // adiciona a nova palavra no endereco da posicao inicial da antiga
            i += tam_correcao; //incrementa o tamanho da nova palavra no resultado
            s += tam_erro; // incrementa o tamanho da antiga palavra no resultado (pq com isso ficam na mesma posicao)
        }
        else
            str_corrigida[i++] = *s++;
    }
    str_corrigida[i] = '\0';

    printf("%s\n", str_corrigida);
    free(str_corrigida);
}

int main(){
    char str[MAX], antiga[20], nova[20];

    while(scanf("%[^\n\r]", str) != EOF){
        scanf("%*c");

        scanf("%[^\n\r]", antiga);
        scanf("%*c");

        scanf("%[^\n\r]", nova);
        scanf("%*c");

        substitui(str, antiga, nova);
    }
    return 0;
}
