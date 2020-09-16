#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void clear (void)
{
while (getchar () != '\n');
}

int main (){
int n_pessoas, i;
char **str;

scanf("%d", &n_pessoas);
clear();

str = (char **)malloc(sizeof(char *) * n_pessoas);
for(i = 0; i < n_pessoas; i++){
    str[i] = (char *)malloc(sizeof(char) * 100);
}
for(i = 0; i < n_pessoas; i++){
    gets(str[i]);
}
for(i = 0; i < n_pessoas; i++){
    printf("%s\n", str[i]);
}
for(i = 0; i < n_pessoas; i++){
    free(str[i]);
}
free(str);
    return 0;
}

