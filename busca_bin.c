#include<stdio.h>

int busca_bin (int v[], int i, int f, int x){

int meio;
meio = (i+f)/2;

    if(f < i){
        return -1;
    }
    if(x == v[meio]){
        return meio;
    }
    else if(x < v[meio]){
        return busca_bin(v, i, meio - 1, x);
    }
    else{
        return busca_bin(v, meio + 1, f, x);
    }
}

int main (){

    int v[] = {1,2,3,3,4,5,7,8,9,10,11,13,15}; //tam = 13
    int indice;
    indice = busca_bin(v, 0, 12, 8); // x ==8
    printf("%d\n", indice);
}
