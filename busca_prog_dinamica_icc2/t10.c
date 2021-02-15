#include<stdio.h>
#include<stdlib.h>

int busca(int x, int tam, int v[]){
    int pos = x % tam; //hashing

    if(v[pos] == x) // verifica se o número existe O(1)
      return pos;
    else{
      pos = 0;
      while(pos < tam){ // busca até acabar o vetor ou até encontrar o num O(n)
        if(v[pos] == x)
          return pos;
        pos++; 
      }

        return -1;
    }
   
}

void inserir(int x, int tam, int v[]){

    if(busca(x, tam, v) != -1){ // confere se ja está no vetor
        return;
    }

    int pos = x % tam; //hashing

    while(pos < tam && v[pos] != -1){ // condição em que existe colisão
      pos = (pos + 1) % tam; // linear
    }

    if(v[pos] == -1) // insere o número
        v[pos] = x;
}

void remover(int x, int tam, int v[]){
    if(busca(x, tam, v) == -1){ // confere se existe o num no vetor
        return;
    }

    int pos = x % tam; //hashing

    while(pos < tam && v[pos] != x){ // condição em que existe colisão
      pos = (pos + 1) % tam; // linear
    }

    if(v[pos] == x) // remove o número
        v[pos] = -1;
    
}

int main (){

    int tam = 0, elem = 0, in = 0, rem = 0, b = 0, i, * v; // inicializa as variáveis

    scanf("%d", &tam); // pega o tamanho do vetor

    v = (int *) calloc(tam, sizeof(int)); // aloca memória para o vetor

    for(i = 0; i < tam; i++){
      v[i] = -1; // inicializa o vetor com -1 (condição vazio)
    }

    scanf("%d", &in); // pega o num de inserções

    for(i = 0; i < in; i++){
        scanf("%d", &elem);
        inserir(elem, tam, v); // insere os números
    }

    scanf("%d", &rem); // pega o num de remoções

    for(i = 0; i < rem; i++){
        scanf("%d", &elem);
        remover(elem, tam, v); // remove os números
    }

    scanf("%d", &b); //pega o num de buscas

    for(i = 0; i < b; i++){
        scanf("%d", &elem);
        printf("%d ", busca(elem, tam, v)); // busca os elementos
    }

    free(v); // libera memória

    return 0;

}
