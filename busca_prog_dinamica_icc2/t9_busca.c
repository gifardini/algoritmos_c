#include <stdio.h>
#include <stdlib.h>

void shell(int v[],int n);
int busca(int v[], int comeco, int fim, int x);
void merge(int v[],int c,int f);
void intercala(int v[],int c1,int f1,int c2,int f2);

int main()
{
	/*Variaveis:
	n=Quantidade de Itens do vetor
	num=Valor do vetor[i]
	k=Quantidade de Itens a buscar
	i=iterador
	resp=Guarda a resposta de existencia da busca
	*v=Vetor alocado dinamicamente
	*/
    int n,num,k,i,resp;
    int *v;

    scanf("%d",&n);
	//Vetor alocado dinamicamente, de tamanho n
    v=(int *)calloc(n,sizeof(int));

	//Leitura dos valores de cada posição do vetor
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        v[i]=num;
    }

	/*Ordenação do Vetor:
	Escolhemos o merge pois é um método que não possui o pior caso com um desempenho tão ruim, 
	além de sua implementação já ser conhecida
	*/
    merge(v,0,n-1);

	//Busca
    scanf("%d",&k);

    for(i=0;i<k;i++)
    {
		//Leitura do Numero a ser buscado
        scanf("%d",&num);
		//Resp recebe o valor da busca -> -1 se não foi possível encontrar
        resp=busca(v,0,n-1,num);

		//Resposta
        if(resp==-1)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
        
    }

	//Desalocação de memória do vetor e fim do programa
	free(v);
    return 0;
}

/* Conjunto de Funções para o Merge
Intercala: Faz a ordenação dentro das duas "metades"
Merge: Coordena as partições e a junção depois de ordenadas
*/
void intercala(int v[],int c1,int f1,int c2,int f2)
{
	int len=(f1-c1+1)+(f2-c2+1);
	int a[len];
	int i1=c1;
	int i2=c2;
	int k=0,i;

	while(i1<=f1 && i2<=f2)
	{
		if(v[i1]<v[i2])
		{
			a[k]=v[i1];
			k++;
			i1++;
		}
		else
		{
			a[k]=v[i2];
			k++;
			i2++;
		}
	}
	while(i1<=f1)
	{
		a[k++]=v[i1++];
	}
	while(i2<=f2)
	{
		a[k++]=v[i2++];
	}

	k=0;

	for(i=c1,k=0;i<=f2;i++,k++)
	{
		v[i]=a[k];
	}
}

void merge(int v[],int c,int f)
{
	int m;

	if(f>c)
	{
		m = (c+f)/2;
		merge(v,c,m);
		merge(v,m+1,f);
		intercala(v,c,m,m+1,f);
	}
}

/* Método de Busca: Binária	
	-Divide o vetor ao meio, pegando o valor dessa posição
		-Se o x==meio então achamos, retornamos o valor
		-Se x<meio então iremos buscar na metade de "baixo", ou primeira metade
		-Se x>meio então iremos buscas na metade de "cima", ou na segunda metade
	-Caso não seja possível encontrar, retorna-se -1.
*/
int busca(int v[], int comeco, int fim, int x)
{
	if(comeco>fim)
	{
		return -1;
	}

	int meio=(comeco+fim)/2;

	if(x==v[meio])
	{
		return meio;
	}

	if(x<v[meio])
	{
		return busca(v,comeco,meio-1,x);
	}
	else
	{
		return busca(v,meio+1,fim,x);
	}
	return 0;
}