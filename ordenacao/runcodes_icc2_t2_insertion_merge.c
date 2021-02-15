#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int c_merge = 0, t_merge = 0, c_insertion = 0, t_insertion = 0;

void insertion(int *v, int n){
    int i;

    for(i = 1; i < n; i++){
        int x = v[i];
        t_insertion++;
        int j = i - 1;
        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j--;
            c_insertion++;
            t_insertion++;
        }

        if(j>=0) c_insertion++;
        v[j+1] = x;
        t_insertion++;
    }
}

void intercala(int *v, int c1, int f1, int c2, int f2){
    int len = (f2 - c1);
    int a[len];
    int i1 = c1, i2 = c2, k = 0;

    while(i1 <= f1 && i2 <= f2){

        if(v[i1] <= v[i2]){
            a[k++] = v[i1++];
            c_merge++;
            t_merge++;
        }
        else{
            a[k++] = v[i2++];
            c_merge++;
            t_merge++;
        }
    }

    while(i1 <= f1){
        t_merge++;
        a[k++] = v[i1++];
    }
    while(i2 <= f2){
        a[k++] = v[i2++];
        t_merge++;
    }
    int i;
    for(i = c1, k = 0; i <= f2; i++, k++){
        v[i] = a[k];
        t_merge++;
    }
}

void merge (int *v, int c, int f){

    if(f > c){
        int m = (c+f)/2;
        merge(v, c, m);
        merge(v, m+1, f);
        intercala(v, c, m, m+1, f);
    }
}

int main(){

    int num_vetores, i, j;

    scanf("%d", &num_vetores);

    int *tam_vetor = (int *)malloc(num_vetores*sizeof(int));
    assert(tam_vetor != NULL);

    for(i = 0; i < num_vetores; i++){
        scanf("%d", &tam_vetor[i]);
    }

    int **v_merge = (int **)calloc(num_vetores, sizeof(int *));

    i = 0;

    while(i < num_vetores){

        v_merge[i] = (int *)calloc(tam_vetor[i], sizeof(int));
        assert(v_merge[i] != NULL);

        i++;
    }

    int **v_insertion = (int **)calloc(num_vetores, sizeof(int *));

    i = 0;

    while(i < num_vetores){

        v_insertion[i] = (int *)calloc(tam_vetor[i], sizeof(int));
        assert(v_insertion[i] != NULL);

        i++;
    }

    for(i = 0; i < num_vetores; i++){
        for(j = 0; j < tam_vetor[i]; j++){
            scanf("%d", &v_merge[i][j]);
            v_insertion[i][j] = v_merge[i][j];
        }
    }

    for(i = 0; i < num_vetores; i++){
        insertion(*(v_insertion+i), tam_vetor[i]);
        printf("I %d %d %d\n", tam_vetor[i], t_insertion, c_insertion);
        c_insertion = 0, t_insertion = 0;
        merge(*(v_merge+i), 0, (tam_vetor[i]) - 1);
        printf("M %d %d %d\n", tam_vetor[i], t_merge, c_merge);
        c_merge = 0, t_merge = 0;
    }

    free(tam_vetor);

    for(i = 0; i < num_vetores; i++){
        free(v_merge[i]);
        free(v_insertion[i]);
    }

    free(v_merge);
    free(v_insertion);

    return 0;
}
