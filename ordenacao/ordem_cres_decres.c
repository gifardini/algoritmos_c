#include<stdio.h>
#include<stdlib.h>
#define max 1000

int main (){

int n, i, ordem = 1;

    scanf("%d", &n);

int *cmp, *v, j = 0;

v = (int *)calloc(n, sizeof(int));
cmp = (int *)calloc(n, sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    for(i = 0; i < n; i++){
        if(v[i] < v[i+1]){
            cmp[j] = 1; /* crescente */
        }
        else if(v[i] > v[i+1]){
            cmp[j] = -1; /* decrescente */
        }
        else if (v[i] == v[i+1]){
            cmp[j] = 0;
        }

        j++;
    }

    for(j = 1; j <= n-1; j++){
            if(cmp[j-1] == 1 && cmp[j] == -1){
                ordem = 0;
                break;
            }
            else if (cmp [j-1] == -1 && cmp[j] == -1){
                ordem = -1;
            }
            else if (cmp[j-1] == 1 && cmp[j] == 1){
                ordem = 1;
            }
    }

    printf("%d\n", ordem);
    free(cmp);
    free(v);
    return 0;
}
