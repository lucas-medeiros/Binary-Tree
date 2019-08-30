#define TAM 11

#include <stdio.h>

#include <stdlib.h>
#include <time.h>

void quickSort(int v[], int l, int r);
void preencheVetor(int v[]);
void mostraVetor(int v[]);

int main() {
   int v[TAM];
   
   preencheVetor(v);
   printf ("Vetor desordenado: \n");
   mostraVetor(v);        
   quickSort(v, 0, TAM-1);
   printf ("\nVetor ordenado: \n");
   mostraVetor(v);  
   return 0;   
}

void quickSort(int v[], int l, int r){
// versão livro do Niklaus Wirth
   int i, j, aux, x;

   i = l; 
   j = r;
   x = v[(l+r)/2];
   printf ("\nEsquerda em [%d] \n", l);
   printf ("Direita em [%d] \n", r);
   printf ("Pivo [%d] = %d\n", (l+r)/2, x);
   do {
   	  while (v[i] < x) i++;
   	  while (x < v[j]) j--;
   	  if (i<=j) {
   	  	 printf ("Permutar %d com %d \n", v[i], v[j]);
   	  	 aux = v[i]; 
		 v[i] = v[j]; 
		 v[j] = aux;
		 i++;
		 j--; 
	  }
   } while (i<=j);	  
   
   mostraVetor(v);     
   if (l < j) quickSort (v, l, j);
   if (i < r) quickSort (v, i, r);
}

void preencheVetor(int v[]) {
   int i;  
   srand(time(NULL));  
   for (i=0; i<TAM; i++) 
       v[i] = 10 + rand()%89;
}

void mostraVetor(int v[]) {   
   int i;
   for (i=0; i<TAM; i++)
       printf ("%d ", v[i]);
   printf ("\n");     
}



