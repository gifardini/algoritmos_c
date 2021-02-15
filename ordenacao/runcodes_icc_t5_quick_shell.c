#include <stdio.h>
#include <stdlib.h>

int quick(int v[], int c, int f){
    
    if(c >= f){
        return 0;
    }

    int cmp = 0, cop = 0;
    int m = (c+f)/2;
    int pivo = v[m];
    cop++;

    int i = c;
    int j = f;

    while(1){
        while(v[i] < pivo){  
            cmp++;
            i++;  
        }
        while(v[j] > pivo){
            cmp++;
            j--;
        }
        if(v[i] >= pivo) cmp++;
        if(v[j] <= pivo) cmp++;
        if(j <= i){
            break;
        }

        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        cop+=3;
        i++;
        j--;
    }
    return (cmp + cop + quick(v, c, j) + quick(v, j+1, f));
}

int shell(int v[], int c, int f){
    int gap = 1, cont = 0;
    int n = f + 1;
    while(gap <= n){
        gap *= 2;
    }
    gap = gap/2 - 1;

    while(gap > 0){
        int k;
        int i;
        int j;
        for(k = 0; k < gap; k++){
           for(i = k + gap; i < n; i+=gap){
            int x = v[i];
            cont++;
            j = i - gap;
            while(j >= 0 && v[j] > x){
                v[j + gap] = v[j];
                cont+=2;
                j-=gap;
            }
            if(j >= 0){ cont++;}
            v[j + gap] = x;
            cont++;
        }
    }
        gap /= 2;
    }
    return cont;
}

int main(){
    int N, **V1, **V2, **operator, x, y, operationShell, operationQuick;
    scanf("%d", &N);

    V1 = malloc(N*(sizeof(int*)));
    V2 = malloc(N*(sizeof(int*)));
    operator = malloc(N*(sizeof(int*)));
    operator[N] = (int*)malloc(N*(sizeof(int)));

    for(y = 0; y < N; y++){
        scanf("%d", &operator[N][y]);
    }

    /*for(x=N-1;x>-1;x--){
        operator[x] = malloc(N*(sizeof(int)));
        for(y=x;y>-1;y--){
            operator[x][y] = operator[N][y];
        }
    }*/

    for(x = 0; x<N; x++){

        V1[x] = (int*)malloc(N*(sizeof(int)));
        V2[x] = (int*)malloc(N*(sizeof(int)));
        
        for(y = 0; y<x+1; y++){
            V1[x][y] = operator[N][y];
            V2[x][y] = V1[x][y];
        }
    }

    for(x=0;x<N;x++){

        operationQuick = quick(V1[x], 0, x);
        operationShell = shell(V2[x], 0, x);

        if(operationQuick < operationShell){
            printf("Q ");
        }
        if(operationQuick > operationShell){
            printf("S ");
        }
        if(operationQuick == operationShell){
            printf("- ");
        }

        free(V1[x]);
        free(V2[x]);

    }
    free(V1); free(V2);
}