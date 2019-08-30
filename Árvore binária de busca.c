// Exemplo de arvore binaria de busca

#define ERRO 		0
#define OK 		 	1

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct sNo {
	int valor;
	struct sNo *esq;
	struct sNo *dir;
};

typedef struct sNo sNo;

sNo *inicializa ();
sNo *cria (int valor, sNo *sae, sNo *sad, int *res);

int e_vazia (sNo *a);
void imprime_in_order (sNo *a);
void imprime_textual (sNo *a);sNo* inserebin (int valor, sNo *a);


sNo* buscabin (int valor, sNo *a);
sNo* inserebin (int valor, sNo *a);
sNo* removebin (int valor, sNo *a);
sNo* liberabin (sNo *a);
	
main() {
	sNo *abb, *b; 
    int r;

    /* Criando a arvore binária de busca ordenada: ------------------------------------------
                       7
                     /   \
                    3     11
				   / \   / \
				  1	 5  9   13
    */    
	abb = inicializa(); 
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
	   	
    abb = inserebin (7, abb);
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
	       
	abb = inserebin (3, abb);
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
	   	
    abb = inserebin (11, abb);
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
	       
    abb = inserebin (1, abb);
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
   	
	abb = inserebin (13, abb);
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
   	
	abb = inserebin (9, abb);
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
   	
	abb = inserebin (5, abb);
	printf ("\n\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
		     
	// exemplos de remocao ---------------------------------------------
    /* retirar valores da arvore ?
       tres possibilidades:
     	   - remocao de folha
     	   - remocao de pai de filho unico
     	   - remocao de pai de dois filhos
    */	
	getch();
	printf ("\n\nRemove o 13 (folha)");
	abb = removebin (13, abb);	     
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
    getch();
	
	printf ("\n\nRemove o 11 (pai de filho unico)");
	abb = removebin (11, abb);	     
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
    getch();

			     
    // fazendo a busca ---------------------------------------------------------------------
	// exemplo buscar 11
    b = buscabin (11, abb);
    if (b != NULL)
	  	printf ("\n\nValor 11 encontrado\n");
	// exemplo buscar 12
    b = buscabin (12, abb);
    if (b == NULL)
    	printf ("Valor 12 nao encontrado\n");

    // inserindo na árvore  ----------------------------------------------------------------
	abb = inserebin (4, abb);
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
    abb = inserebin (8, abb);
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
    abb = inserebin (15, abb);
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
    abb = inserebin (12, abb);
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
    //
	// como ficou a arvore agora ?
    //
   	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);

    
  	// exemplo buscar 11
    b = buscabin (11, abb);
    if (b != NULL)
	  	printf ("\n\nValor 11 encontrado\n");
	// exemplo buscar 12
    b = buscabin (12, abb);
    if (b != NULL)
    	printf ("\nValor 12 encontrado\n");
    b = buscabin (17, abb);
    if (b != NULL)
    	printf ("Valor 17 encontrado\n");
    else printf ("Valor 17 nao encontrado\n");

    abb = inserebin (17, abb);
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
   	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
    b = buscabin (17, abb);
    if (b != NULL)
    	printf ("\nValor 17 encontrado\n");
    else printf ("Valor 17 nao encontrado\n");

    /* retirar valores da arvore ?
       tres possibilidades:
     	   - remocao de folha
     	   - remocao de pai de filho unico
     	   - remocao de pai de dois filhos
    */

	printf ("\n\nRemove o 9 (pai de dois filhos)");
	abb = removebin (9, abb);	     
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
	printf ("\n:: Textual (pre-order): ");
   	imprime_textual (abb);
    getch();
    
    // libera toda a arvore
    printf ("\n\nExemplo liberando toda a arvore: ");
    abb = liberabin (abb);
	printf ("\n:: In-order: ");
    imprime_in_order (abb);
   	printf ("\n:: Textual (pre-order): ");

}

// definicao recursiva de arvore binaria:
// 1) uma arvore binaria eh vazia, ou
sNo *inicializa (void) {
	return NULL;
}

// 2) eh composta por uma raiz e duas sub-arvores (esquerda e direita)
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

// impressao dos nos da arvore de busca em ordem crescente
// usando percurso in-order/ordem simétrica: 
// percorre sae, trata raiz, percorre sad
// também conhecido como caminhamento central
void imprime_in_order (sNo *a){
	if (!e_vazia(a)) {
		imprime_in_order (a->esq);
		printf (" %d ", a->valor);	
		imprime_in_order (a->dir);
	}
}

// representacao textual, percurso eh pre-order: raiz, sae, sad
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

// busca binária explorando o fato da árvore ser ordenada
sNo* buscabin (int valor, sNo *a){
	if (a == NULL) 
		return NULL;
	else if (a->valor > valor) 
	    return buscabin (valor, a->esq);
	else if (a->valor < valor)  
		return buscabin (valor, a->dir);
	else return a;
}

// insere no local correto mantendo a ABB
sNo* inserebin (int valor, sNo *a){
	int r;
	if (e_vazia(a)) 	
		a = cria (valor, NULL, NULL, &r);
	else 
	if (valor < a->valor) 
	     a->esq = inserebin (valor, a->esq);
	else if (valor > a->valor)  
		 a->dir = inserebin (valor, a->dir);
	return a;
}
		

// libera toda a memoria alocada para a arvore
// liberando as subarvore antes da raiz
sNo* liberabin (sNo *a) {
	if (!e_vazia(a)) {
		printf ("\n:: In-order: ");
		imprime_in_order (a);		
		liberabin (a->esq); // libera sae
		liberabin (a->dir); // libera sad
		free (a);
	}
	return NULL;
}

// remove valor da arvore a
sNo* removebin (int valor, sNo *a) {
	if (e_vazia(a)) 
		return NULL;
	else if (valor < a->valor) 
	     a->esq = removebin (valor, a->esq);
	else if (valor > a->valor)  
		 a->dir = removebin (valor, a->dir);
	else {  // encontrou no a remover
		// remocao de folha
		if (a->esq == NULL && a->dir == NULL) { 
			free (a);
			a = NULL;
		}
		// filho unico a direita 
		else if (a->esq == NULL) { 
			sNo* temp = a;
			a = a->dir;
			free (temp);
		}
		// filho unico a esquerda 
		else if (a->dir == NULL) { 
			sNo* temp = a;
			a = a->esq;
			free (temp);
		}
		// pai de dois filhos
		else { 
			sNo* filho = a->dir;
			while (filho->esq != NULL) {
				filho = filho->esq;
			}
			a->valor = filho->valor; // troca as informações
			filho->valor = valor;
			a->dir = removebin(valor, a->dir);
		}		
	}
	return a;
} 		