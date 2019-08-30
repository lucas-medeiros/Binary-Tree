#define TAM 10

#include <stdio.h>

#include <stdlib.h>
#include <time.h>

void ordenaSelecao(int v[]);
void preencheVetor(int v[]);
void mostraVetor(int v[]);

int main() {
   int v[TAM];
   
   preencheVetor(v);
   printf ("Vetor desordenado: \n");
   mostraVetor(v);        
   ordenaSelecao(v);
   printf ("\nVetor ordenado: \n");
   mostraVetor(v); 
   return 0;    
}

void ordenaSelecao(int v[]) {
   int i, j, menor, aux;
   for (j=0; j <TAM-1; j++) {
	   printf ("\nPasso %d: ", j);
   	   mostraVetor(v);

       menor = j;
       for (i=j+1; i<TAM; i++) {
           if (v[i] < v[menor]) 
              menor = i;
       }
       aux = v[j];
       v[j] = v[menor];
       v[menor] = aux;                   
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


