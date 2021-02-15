#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void heapify(int v[], int p, int u){
    while(p <= u){
        int f = 2*p + 1;
        if(f <= u){
            if(f+1 <= u){
                //dois filhos
                if(v[f+1] > v[f])
                    f++;
            }
            // f é o maior dos filhos
            if(v[f] > v[p]){
                int tmp = v[f];
                v[f] = v[p];
                v[p] = tmp;
            }
        }
        p = f;
    }
}

void heap(int v[], int n){
    int i;
    for(i = (n - 1)/ 2; i >= 0; i--){
        heapify(v, i, n-1);
    }
    for(i = n - 1; i > 0; i--){
        int tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        heapify(v, 0, i - 1);
    }

}

int main (void){
    int n, *v, i;
    printf("Digite o tamanho do vetor ");
    scanf("%d", &n);
    v = (int *)calloc(n, sizeof(int));
    assert(v != NULL);
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    heap(v, n);
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}