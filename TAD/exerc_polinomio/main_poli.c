#include<stdlib.h>
#include<stdio.h>
#include"polinomio.h"
#include<string.h>

int main(){
    poli_t *poli = criar();
    char vars[10];
    int exps[10];

    strcpy(vars, "xyz");
    exps[0] = 2; exps[1] = 3; exps[2] = 1;
    add_term(poli, 4, vars, exps);

    strcpy(vars, "xy");
    exps[0] = 1; exps[1] = 1;
    add_term(poli, 3, vars, exps);

    strcpy(vars, "");
    add_term(poli, 5, vars, exps);

    imprimir(poli);

    int x = 2;
    int y = 3;
    int z = 1;

    printf("%d\n", calcula_xyz(poli, x, y, z));
    liberar(poli);

    return 0;
}