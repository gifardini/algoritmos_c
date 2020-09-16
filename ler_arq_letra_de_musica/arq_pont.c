#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (){

char *str, mat[100][100];
FILE *arq;
int i = 0, linhas = 0;


    if((arq=fopen("melancholy_hill.txt", "r+"))==NULL)
        printf("\nErro abrindo arquivo.\n");

    while(!feof(arq)){ //lembre do feof
        fgets(mat[i++], sizeof(mat[i]), arq);
        linhas++;
    }

int j;

    for(j = 0; j < linhas; j++){
            printf("%s", mat[j]);
    }
    printf("\n");

fclose(arq);

    return 0;
}
