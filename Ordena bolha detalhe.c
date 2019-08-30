#define TAM 10

#include <stdio.h>

#include <stdlib.h>
#include <time.h>

void ordenaBolha(int v[]);
void preencheVetor(int v[]);
void mostraVetor(int v[]);

int main() {
   int v[TAM];
   
   preencheVetor(v);
   printf ("Vetor desordenado: \n");
   mostraVetor(v);        
   ordenaBolha(v);
   printf ("\nVetor ordenado: \n");
   mostraVetor(v);  
   return 0;   
}

void ordenaBolha(int v[]) {
   int i, j, aux;
   for(i = TAM-1; i > 0; i--) {
      mostraVetor(v);   	
      for(j = 0; j < i; j++) {
         if (v[j] > v[j+1]) {
            aux = v[j]; 
			v[j] = v[j+1]; 
			v[j+1] = aux; 
		 }
		mostraVetor(v); 
      }
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
