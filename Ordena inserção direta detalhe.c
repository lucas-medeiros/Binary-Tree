#define TAM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenaInsercao(int v[]);
void preencheVetor(int v[]);
void mostraVetor(int v[]);

int main() {
   int v[TAM];
   
   preencheVetor(v);
   v[9]=1;
   printf ("Vetor desordenado: \n");
   mostraVetor(v);        
   ordenaInsercao(v);
   printf ("\nVetor ordenado: \n");
   mostraVetor(v);     

   return 0;
}

void ordenaInsercao(int v[]) {
   int i, j, aux;
   for(i = 1; i < TAM; i++) {
	  aux = v[i];
	  j = i - 1;
	  while (j >= 0 && v[j] > aux) {
	     v[j+1] = v[j];
	     j--;  
       printf ("\nPasso %d-%d: ", i,j);
       mostraVetor(v);
	  }
	  v[j+1] = aux;
    printf ("\nPasso %d-%d: ", i,j);
    mostraVetor(v);
	}
}

void preencheVetor(int v[]) {
   int i;  
   srand(time(NULL));  
   for (i=0; i<TAM; i++) 
       v[i] = 1 + rand()%99;
}

void mostraVetor(int v[]) {   
   int i;
   for (i=0; i<TAM; i++)
       printf ("%02d ", v[i]);
   printf ("\n");     
}