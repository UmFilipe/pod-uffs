/**
 * @file comparacaoMetodos.c
 * @author Eduardo_Pazzini_Zancanaro_e_Filipe_Medeiros_de_Almeida
 * @version 0.1
 * @date 2023-09-22
 *
 * @copyright Copyright (c) 2023
 *
 *
  * Atenção: Antes de entregar, conferir se dos dados acima da documentação estão
 * preenchidos corretamente.
 *
 */
#include <stdio.h>

void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void quickSort(int *A, int size);

void printArray(int n, int *ptr) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", ptr[i]);
  }
  printf("\n");
}

void swap (int *a, int *b){
   int temp=*(b);
   *b=*a;
   *a=temp;
};

int main(){

	int i;
	int vetor[] = {1, 20, -10, 30, 5, 7};
	int tamanhoVetor = (int)sizeof(vetor)/sizeof(int);

	printf("\nVetor original: ");
	for (i = 0; i < tamanhoVetor; i++)
    	printf("%d ", vetor[i]);

	printf("\nVetor tamanho = %d\n", tamanhoVetor);

	// bubble sort
	int bubbleVec[tamanhoVetor];
	copia(vetor, bubbleVec, tamanhoVetor);
	bubbleSort(bubbleVec, tamanhoVetor);
	printf("\nBubble sort: ");
	for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", bubbleVec[i]);
	printf("\n");

	// selection sort

	// insertion sort

	// quick sort

	return 0;
}

void copia(int *A, int *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

void bubbleSort(int *A, int size){
   int i, j;   
    for (i = 0; i < size; i++) {   
        for (j = i + 1; j < size; j++) {   
            if (*(A + j) < *(A + i)) {   
                swap((A + j), (A + i));  
            } 
        } 
    }   
    printf("Vetor ordenado:");
    printArray(size,A);
    printf("\n");

}

void selectionSort(int *A, int size){
    int count = 0;

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        //find min index
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;

            }
        }

        if (min_index != i) {
            int temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
        }
    }

	printf("Vetor ordenado com selection\n");
    printArray(size, A);

}

void insertionSort(int *A, int size){
   	int i,j, min, t;
    int contador=0;
    for (i = 1; i < size; i++) {   
        
        min=A[i];
        for (j=i; j>=1 && min< A[j-1];j--){
            A[j]=A[j-1];
           
        }   
        A[j]=min;
    }
    printf("Vetor ordenado com insertion\n");
    printArray(size, A);
    printf("contador %i", contador);

}

void quickSort(int *A, int size){
   // implementação do Quick

}




