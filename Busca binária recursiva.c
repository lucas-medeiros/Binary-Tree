#include <stdio.h>

#include <stdlib.h>
#include <time.h>

int pesquisaBinRec (int x, int e, int d, int v[]);
void quickSort(int v[], int l, int r);
void preencheVetor(int v[]);
void mostraVetor(int v[]);

int main() {
   int v[TAM];
   int x, i;
   
   preencheVetor(v);
   printf ("Vetor desordenado: \n");
   mostraVetor(v);        
   quickSort(v, 0, TAM-1);
   printf ("\nVetor ordenado: \n");
   mostraVetor(v);
   printf ("\nQual valor procurar: ");
   scanf ("%d", &x);
   
   if ((i = pesquisaBinRec (x, 0, TAM, v)) >= 0)
      printf ("Encontrado ocorrencia de %d na posicao [%d]\n", x, i);     
   else printf ("Valor %d nao existe no vetor\n", x);  

   return 0;   
}

int pesquisaBinRec (int x, int e, int d, int v[]) {
   if (e > d) return -1;
   else {
      int m = (e + d)/2;
      if (v[m] == x) return m;
      if (v[m] < x)  
         return pesquisaBinRec (x, m+1, d, v);
      else  
         return pesquisaBinRec (x, e, m-1, v); 
   } 
}


void quickSort(int v[], int l, int r){
   int i, j, aux, x;
   i = l; 
   j = r;
   x = v[(l+r)/2];
   do {
   	  while (v[i] < x) i++;
   	  while (x < v[j]) j--;
   	  if (i<=j) {
   	  	 aux = v[i]; 
		 v[i] = v[j]; 
		 v[j] = aux;
		 i++;
		 j--; 
	  }
   } while (i<=j);	  
   if (l < j) quickSort (v, l, j);
   if (i < r) quickSort (v, i, r);
}

void preencheVetor(int v[TAM]) {
   int i;  
   srand(time(NULL));  
   for (i=0; i<TAM; i++) 
       v[i] = 1 + rand()%999;
}

void mostraVetor(int v[TAM]) {   
   int i;
   for (i=0; i<TAM; i++) {
       printf ("[%2d]: %3d  ", i, v[i]);
       if ((i+1)%10==0) printf ("\n");
   }
   printf ("\n");     
}





