// Exemplos de criacao e manipulacao de arvores binarias

#define ERRO 		0
#define OK 		 	1

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// estrutura de um elemento, no da arvore
struct sNo {
	int valor;
	struct sNo *esq;
	struct sNo *dir;
};

typedef struct sNo sNo;

sNo *inicializa ();
sNo *cria (int valor, sNo *sae, sNo *sad, int *res);

int e_vazia (sNo *a);
int busca (int valor, sNo *a);

void imprime_pre_order (sNo *a);
void imprime_in_order (sNo *a);
void imprime_pos_order (sNo *a);
void imprime_textual (sNo *a);

int altura (sNo *a);
int qtdeNos (sNo *a);
int qtdeFolhas (sNo *a);

main() {
    sNo *a0, *a1, *a2, *a3, *a4, *a5; // exemplo 1
    sNo *a10; // exemplo 2
    sNo *a20; // exemplo 3: arvore com um unico no raiz
	sNo *a30; // exemplo 4: para exemplo de arvore vazia
    int r, v;
  
    /*  Exemplo 1 ------------------------------------------------------------------------
	    Criando a seguinte arvore: 
                       0
                     /   \
                    1     2
					 \   / \
					 3  4   5
    */
    a3 = cria (3, inicializa(), inicializa(), &r);
    a4 = cria (4, inicializa(), inicializa(), &r);
    a5 = cria (5, inicializa(), inicializa(), &r);
    a1 = cria (1, inicializa(), a3, &r);
    a2 = cria (2, a4, a5, &r);
    a0 = cria (0, a1, a2, &r);  
    if (r) {    	
    	printf (":: Arvore a0 criada!");
		printf ("\n:: Pre-order: ");
    	imprime_pre_order (a0);  	
		printf ("\n:: In-order: ");
    	imprime_in_order (a0);
		printf ("\n:: Pos-order: ");
    	imprime_pos_order (a0);
		printf ("\n:: Textual: ");
    	imprime_textual (a0);
    	printf ("\n:: a0 possui %d nos", qtdeNos(a0));
    	printf ("\n:: a0 possui %d folhas", qtdeFolhas(a0));
     	printf ("\n:: a0 possui altura de %d \n", altura(a0));
     	
     	getch();
    }
    else printf ("=> Erro na criacao da arvore!\n");
      
   
    /* Exemplo 2 -----------------------------------------------------------------------------
	   Outro exemplo de arvore e formato para criacao:
                     10
                   /   \
                  20   21
    */
    a10 = cria (10, 
                   cria (20, NULL, NULL, &r), 
	  			   cria (21, NULL, NULL, &r), 
	 			   &r);
    if (r) {    	
    	printf ("\n\n:: Arvore a10 criada!");
    	printf ("\n:: Pre-order: ");
		imprime_pre_order (a10);
 		printf ("\n:: Textual: ");
    	imprime_textual (a10);
    	printf ("\n:: a10 possui %d nos", qtdeNos(a10));
    	printf ("\n:: a10 possui %d folhas", qtdeFolhas(a10));
    	printf ("\n:: a10 possui altura de %d \n", altura(a10));
    }
    else printf ("=> Erro na criacao da arvore!\n");


	// Exemplo do usa da funcao de busca -----------------------------------------------------
	if (busca(4, a0)) printf ("\n\nValor 4 esta presente na arvore a0\n");
	if (!busca(4, a10)) printf ("Valor 4 nao esta presente na arvore a10\n");
    getch();

    // Exemplo 3 -----------------------------------------------------------------------------
	// arvore com um unico no raiz
    a20 = cria (20, inicializa(), inicializa(), &r); 
    if (r) {    	
    	printf ("\n\n:: Arvore a20 criada!");
		printf ("\n:: Pre-order: ");
    	imprime_pre_order (a20);
		printf ("\n:: Textual: ");
    	imprime_textual (a20);    	
    	printf ("\n:: a0 possui %d nos", qtdeNos(a20));
    	printf ("\n:: a0 possui %d folhas", qtdeFolhas(a20));
     	printf ("\n:: a0 possui altura de %d \n", altura(a20));
    }
    else printf ("=> Erro na criacao da arvore!\n");
 	
 
 	// Exemplo 4 ---------------------------------------------------------------------------
	// Arvore vazia
    a30 = inicializa(); 
    if (r) {    	
    	printf ("\n\n:: Arvore a30 criada!");
		printf ("\n:: Pre-order: ");
    	imprime_pre_order (a30);
  		printf ("\n:: Textual: ");
    	imprime_textual (a30);
     	printf ("\n:: a0 possui %d nos", qtdeNos(a30));
    	printf ("\n:: a0 possui %d folhas", qtdeFolhas(a30));
     	printf ("\n:: a0 possui altura de %d \n", altura(a30));
    }
    else printf ("=> Erro na criacao da arvore!\n");
 		
}
  
// definicao recursiva de arvore binaria:
// 1) uma arvore binaria eh vazia, ou
sNo *inicializa (void) {
	return NULL;
}
// 2) eh composta por uma raiz e duas subarvores (esquerda e direita)
sNo *cria (int valor, sNo *sae, sNo *sad, int *res) {
	sNo *no;
	no = (sNo *) malloc (sizeof(sNo));
	if (no == NULL) *res = ERRO;
	else {
		no->esq = sae;
		no->dir = sad;
		no->valor = valor;
		*res = OK;
	}
	return no;
}

// verifica se arvore a eh vazia
int e_vazia (sNo *a){
	return a == NULL;
}

// indica ocorrencia ou nao do valor na arvore
int busca (int valor, sNo *a){
	if (e_vazia(a)) 
		return 0;
	else // encontra ou busca a esquerda ou busca a direita, interrompe assim que achar
	    return a->valor==valor || busca(valor, a->esq) || busca(valor, a->dir); 
}

// impressao dos nos da arvore:
//    -> pre-order/pré-ordem: trata raiz, percorre sae, percorre sad
//    -> in-order/ordem simétrica: percorre sae, trata raiz, percorre sad
//    -> pos-order/pós-ordem: percorre sae, percorre sad, trata raiz
void imprime_pre_order (sNo *a){
	if (!e_vazia(a)) {
		printf (" %d ", a->valor);	
		imprime_pre_order (a->esq);
		imprime_pre_order (a->dir);
	}
}

void imprime_in_order (sNo *a){
	if (!e_vazia(a)) {
		imprime_in_order (a->esq);
		printf (" %d ", a->valor);	
		imprime_in_order (a->dir);
	}
}

void imprime_pos_order (sNo *a){
	if (!e_vazia(a)) {
		imprime_pos_order (a->esq);
		imprime_pos_order (a->dir);
		printf (" %d ", a->valor);	
	}
}

// representacao textual, percurso eh pre-order
void imprime_textual (sNo *a){
	if (e_vazia(a))
		printf ("<>");
	else {
		printf ("<%d", a->valor);	
		imprime_textual (a->esq);
		imprime_textual (a->dir);
		printf (">");
	}
}

// retorna a altura da arvore
int altura (sNo *a){
	int ae, ad;
	
	if (a == NULL) 
		return -1; // arvore vazia tem altura -1 
	else if (a->esq == NULL && a->dir == NULL)	
		return 0; // arvore com apenas raiz tem altura 0
	else {
		ae = altura (a->esq);
		ad = altura (a->dir);
		if (ae > ad)
			return 1 + ae;
		else
			return 1 + ad;
	}
}

// retorna a quantidade de nos da arvore
int qtdeNos (sNo *a){
	if (a == NULL)
		return 0;
	else
		return 1 + qtdeNos (a->esq) + qtdeNos (a->dir);	
}

// retorna a quantidade de folhas (nos sem filhos) da arvore
int qtdeFolhas (sNo *a){
	if (a == NULL)
		return 0;
	if (a->esq == NULL && a->dir == NULL)
	    return 1;
	return qtdeFolhas (a->esq) + qtdeFolhas (a->dir);	
}