#include <stdlib.h>
#include <stdio.h>

#define TAM 10

void printv(int vetor[TAM], int inicio, int fim){
    for(int i=0;i<10;i++) printf("%d\t",vetor[i]);
    printf("\n");
}

void quickSort(int vetor[TAM],int inicio, int fim){
    int pivo,aux,i,j;
    
    i=inicio;
    j=fim-1;
    pivo = vetor[(inicio+fim)/2];
    printf("%d\n",pivo);
    printv(vetor,inicio,fim);
    
    
    while(i<=j){
        while(vetor[i]<pivo && i<fim) i++;
        while(vetor[j]>pivo && j>inicio) j--;
        if(i<=j){
            aux=vetor[i];
            vetor[i]=vetor[j];
            vetor[j]=aux;
            i++;
            j--;
        }
    }
    if(j>inicio) quickSort(vetor,inicio,j+1);
    if(i<fim) quickSort(vetor,i,fim);
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void down_adjust(int heap[],int i)
{
	int j,temp,n,flag=1;
	n=heap[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;    //j points to left child
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}

void create(int heap[])
{
	int i,n;
	n=heap[0]; //no. of elements

	for(i=n/2;i>=1;i--)
		down_adjust(heap,i);
}



void heapSort(int heap[TAM],int n){

    int i,last,temp;
    //create a heap
	heap[0]=n;
	create(heap);

	//sorting
	while(heap[0] > 1)
	{
		//swap heap[1] and heap[last]
		last=heap[0];
		temp=heap[1];
		heap[1]=heap[last];
		heap[last]=temp;
		heap[0]--;
		down_adjust(heap,1);
	}
}

  /* Definição da função bubble_sort */
void bubble_sort (int vet[], int max) {      
    int flag, i, aux;   
    
    do {
      flag = 0;
      for (i = 0; i < (max - 1); i++) {
   
   /* Verfica se o vetor está em ordem, no caso ele coloca em ordem crescente, para decrescente trocar '>' por '<' */
   if (vet[i] > vet[i+1]) {
     /* Caso não esteja, ordena */
     aux = vet[i];
     vet[i] = vet[i+1];
     vet[i+1] = aux;
     flag =1;
   }
      }
    /* Repete enquanto algum valor estiver fora de ordem */  
    } while (flag == 1);
    
}

int main(){
    
    int v[10] = {5, 8, 1, 2, 7, 3, 6, 9, 4, 10};
    printv(v,0,9);
    printf("Ordenado:\n");
    quickSort(v,0,10);
    printv(v,0,9);
}
