#include <stdio.h>
#include <stdlib.h>

/* COLOQUE DEBUG 1 PARA VER O ANDAMENTO DO ALGORITMO */
#define DEBUG 0

#define NEW 0 
#define VER 1 
#define SRC 3 
#define FIN 4 
#define FAIL 5
#define ALR 6 
#define AVLS 8

//Define o ponteiro de struct no como 'Node' para compactar o codigo
typedef struct no* Node; 

//'No': possui um valor(data) e a informacao de sua altura(height)
// 		e possui outros dois 'Nos' na "esquerda" e "direita" 
struct no {
	int data, height;
	Node esq, dir;
};

//var GLOBAL (com o unico proposito de debuggar o codigo)
Node root=NULL;

int height(Node);
int AVL(Node);
int max(int, int);
void debug(int, int, Node);
Node newNode(int);
Node RotRight(Node);
Node RotLeft(Node);
Node insertNode(Node, int);
Node searchNode(Node, int);

int main(int argc, char *argv[]) {

	//Variaveis
	Node srcNode;
	int n, src;

	//Input tamanho do vetor 
	scanf("%i",&n);

	//Inserção dos elementos na arvore AVL
	for(int i = 0, aux; i < n; i++) {
		scanf("%i", &aux);
		root = insertNode(root, aux);
	}

	//Input tamanho do vetor de busca
	scanf("%d",&src);

	//Busca
	for(int i = 0; i < src; i++) {

		scanf("%d",&n);

		debug(SRC, n, root);

		srcNode = searchNode(root,n);

		//Print resultado: 0 = Nao encontrado; 1 = Encontrado;
		if(srcNode==NULL) printf("0\n");
		else printf("1\n");
	}

	return 0;
}

Node newNode(int x) {

	Node aux = (Node) malloc(sizeof(struct no));

	//Atribui 'x' para o novo no
	aux->data = x;
	//Um novo no nao possui filhos 
	aux->esq = NULL; aux->dir = NULL;
	//E possui altura = 1, por definicao
	aux->height = 1;

	return aux;
}

//Funcao rotaciona um ramo a "direita"
Node RotRight(Node N) {
	/*Variaveis auxiliares son = "filho a esquerda";
		gson = "neto a esquerda-direita"*/ 
	Node son = N->esq; 
	Node gson = son->dir; 

	//Print rotacionar a direita
	if(DEBUG==1) printf("Rotate right\n");

	//Rotacao a direita
	son->dir = N; 
	N->esq = gson; 

	//Redefinir "alturas"
	N->height 	= 1 + max(height(N->esq), height(N->dir)); 
	son->height = 1 + max(height(son->esq), height(son->dir)); 

	return son; 
} 

//Funcao rotaciona um ramo a "esquerda"
Node RotLeft(Node N) { 
	/*Variaveis auxiliares son = "filho a direita";
		gson = "neto a direita-esquerda"*/ 
	Node son = N->dir; 
	Node gson = son->esq; 

	//Print rotacionar a direita
	if(DEBUG==1) printf("Rotate left\n");

	//Rotacao a esquerda
	son->esq = N;
	N->dir=gson;

	//Redefinir "alturas"
	N->height 	= 1 + max(height(N->esq), height(N->dir)); 
	son->height = 1 + max(height(son->esq), height(son->dir)); 

	return son; 
} 

//Procura recursivamente um lugar pra inserir o valor 'x' na "arvore" e, em seguida, equilibra
Node insertNode(Node node, int x) {

	//'no' auxiliar com o unico proposito de debuggar o codigo
	Node aux;

	/* Caso base. A esse ponto, o caso NULL diz que estamos na base da "arvore"
		Entao podemos criar uma nova "folha" */
	if( node==NULL ) {

		//Print primeiro 'no' inserido
		if(root==NULL) if(DEBUG==1) printf("\nNode %i created!\n", x);
		debug(AVLS, x, node);
		return newNode(x);
	}

	//Caso 'x' menor que o valor de 'node', insira para "esquerda"
	if( x < node->data ) {

		//Print novo 'no'
		if(node->esq==NULL) debug(NEW, x, node);

		node->esq = insertNode(node->esq, x);		
	}

	//Caso 'x' maior que o valor de 'node', insira para "direita"
	else if( x > node->data ){

		//Print novo 'no'
		if(node->dir==NULL) debug(NEW, x, node);

		node->dir = insertNode(node->dir, x);
	}

	//Caso 'x' igual ao valor de 'node', ignore a inclusao
	else {
		//Print "ja incluido"
		debug(ALR, x, node);
		return node;
	}

	/*Variaveis auxiliares para facilitar a leitura do codigo
	son_dir = "filho a direita"; son_esq = "filho a esquerda"*/
	Node son_dir = node->dir;
	Node son_esq = node->esq;

	//Aumenta a "altura" em 1 + "altura do filho mais alto"
	node->height = 1 + max(height(son_esq), height(son_dir));

	//Print equilibrio do 'node' em questao
	debug(AVLS, 0, node);

	//Caso 1: rotateRight
	if(AVL(node) == -2 && x < son_esq->data) {
		//Print rotacao a direita
		aux = RotRight(node);
		if(node==root) debug(VER, 0, node);
		return aux;
	}

	//Caso 2: rotateLeft -> rotateRight
	if(AVL(node) == -2 && x > son_esq->data) {
		node->esq = RotLeft(node->esq);
		aux = RotRight(node);
		if(node==root) debug(VER, 0, node);
		return aux;
	}

	//Caso 3: rotateLeft
	if(AVL(node) == 2 && x > son_dir->data) {
		aux = RotLeft(node);
		if(node==root) debug(VER, 0, node);
		return aux;
	}

	//Caso 4: rotateRight -> rotateLeft
	if(AVL(node) == 2 && x < son_dir->data) {
		node->dir = RotRight(node->dir);
		aux = RotLeft(node);
		if(node==root) debug(VER, 0, node);
		return aux;
	}

	if(node==root) debug(VER, 0, node);

	return node;

}

//Funcao que busca recursivamente 'x' na arvore
Node searchNode(Node node, int x) {

	//Caso base. A esse ponto, nao ha 'x' na arvore, entao retorna NULL
	if( node == NULL ) {

		//Print nao encontrado
		debug(FAIL, x, node);

		return NULL;
	}

	//Caso 'node' possua o valor desejado
	else if( node->data == x ) {

		//Print encontrado
		debug(FIN, x, node);

		return node;
	}

	//Caso menor que 'data', entao procure a esquerda
	else if( x < node->data ) {

		//Print "procurando para a esquerda"
		if(DEBUG==1) printf("<-");

		return searchNode(node->esq, x);
	}

	//Caso maior que 'data', entao procure a direita
	else {

		//Print "procurando para a direita"
		if(DEBUG==1) printf("->");

		return searchNode(node->dir, x);
	}
}

//Funcao auxiliar: Calcula da altura de um 'no'
int height(Node node) {

	//Caso NULL, retorna 0 (evita Segmentation Fault)
	if(node==NULL) return 0;

	//Retorna a variavel "altura" de 'node'
	else return node->height;
}

//Funcao auxiliar: Calcula o equilibrio de um 'no'
int AVL(Node node) {

	//Caso NULL, retorna 0 (evita Segmentation Fault)
	if(node==NULL) return 0;

	//Retorna a diferenca entre a "altura" da "esquerda" e "direita"
	else return height(node->dir)-height(node->esq);
}

//Funcao auxiliar: Retorna o maior valor entre 'a' e 'b'
int max(int a, int b) {
	//Ternary operator
	return a>b ? a:b;
}

//Funcao com prints que ajudam a visualizar andamento do algoritmo
void debug(int id, int x, Node N) {
	if(DEBUG==1) {
		if(id==AVLS) {
			if(N==NULL)
				printf("AVL for Node %i: 0 (Leaf)\n", x);
			else 
				printf("AVL for Node %i: %i (Left: %i Right: %i)\n",
				N->data, AVL(N), height(N->esq), height(N->dir));	
		}
		else if(id==NEW)
			if( x < N->data )
				printf("\nNode %i has been inserted left from Node %i\n", x, N->data);
			else
				printf("\nNode %i has been inserted right from Node %i\n", x, N->data);
		else if(id==VER)
			printf("The tree is balanced\n");
		else if(id==SRC)
			printf("\nSearching for Node %i...\n", x);
		else if(id==FIN)
			printf("o Node %i found!\n", x);
		else if(id==ALR)
			printf("\nNode %i already on the tree!\n", x);
		else if(id==FAIL)
			printf("x Node %i not found!\n", x);
	} else return;
}