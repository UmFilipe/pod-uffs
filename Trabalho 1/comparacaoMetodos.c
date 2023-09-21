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
#include <stdlib.h>
#include <time.h>

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

void copia(int *A, int *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}


void bubbleSort(int *A, int size){
   int i, j;
   int contador = 0;   
    for (i = 0; i < size; i++) {   
        for (j = i + 1; j < size; j++) {   
            if (*(A + j) < *(A + i)) {   
                swap((A + j), (A + i));  
                contador++;
            } 
        } 
    }   

    printf("Contador de trocas no bubble: %i", contador);

}

void selectionSort(int *A, int size){
    int contador = 0;

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
            contador++;
        }
    }

    printf("Contador de trocas no selection: %i", contador);
}

void insertionSort(int *A, int size){
   	int i,j, min;
    int contador=0;
    for (i = 1; i < size; i++) {   
        min=A[i];
        for (j=i; j>=1 && min< A[j-1];j--){
            A[j]=A[j-1];
            contador++;
        }   
        A[j]=min;
        contador++;
    }

    printf("Contador de trocas no insertion: %i", contador);

}

int quickSortAux(int *A, int baixo, int alto) {
    int pivo = A[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (A[j] < pivo) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[alto]);
    return (i + 1);
}

void quickSort(int *A, int baixo, int alto) {
    if (baixo < alto) {
        int indicePivo = quickSortAux(A, baixo, alto);
        quickSort(A, baixo, indicePivo - 1);
        quickSort(A, indicePivo + 1, alto);
    }

}

int main(){

	int i;
	long int tamanhoVetor = 10000;
	int *vetor = (int*)malloc(tamanhoVetor * sizeof(int));

    for (i = 0; i < tamanhoVetor; i++){
        vetor[i]=(rand()%tamanhoVetor);
    } 

	printf("\nVetor original: \n");
	printArray(tamanhoVetor, vetor);

	printf("\nVetor tamanho = %ld\n", tamanhoVetor);

	// bubble sort
	int bubbleVec[tamanhoVetor];
	copia(vetor, bubbleVec, tamanhoVetor);

    printf("\nBubble sort: \n");
    clock_t inicioBubble = clock();    
    bubbleSort(bubbleVec, tamanhoVetor);
    clock_t fimBubble = clock();
    double tempoBubble = (double)(fimBubble - inicioBubble) / CLOCKS_PER_SEC;

    printf("\nVetor ordenado pelo bubble sort: \n");
    // printArray(tamanhoVetor, bubbleVec);
    printf("Bubble sort demorou: %f segundos", tempoBubble);
    printf("\n");
    

	// selection sort
    int selectionVec[tamanhoVetor];
	copia(vetor, selectionVec, tamanhoVetor);

    printf("\nSelection sort: \n");
    clock_t inicioSelection = clock();    
	selectionSort(selectionVec, tamanhoVetor);
    clock_t fimSelection = clock();
    double tempoSelection = (double)(fimSelection - inicioSelection) / CLOCKS_PER_SEC;

    printf("\nVetor ordenado pelo selection sort: \n");
    // printArray(tamanhoVetor, selectionVec);
    printf("Selection sort demorou: %f segundos", tempoSelection);
    printf("\n");


	// insertion sort
    int insertionVec[tamanhoVetor];
	copia(vetor, insertionVec, tamanhoVetor);

    printf("\nInsertion sort: \n");
    clock_t inicioInsertion = clock();    
	insertionSort(insertionVec, tamanhoVetor);
    clock_t fimInsertion = clock();
    double tempoInsertion = (double)(fimInsertion - inicioInsertion) / CLOCKS_PER_SEC;

    printf("\nVetor ordenado pelo insertion sort: \n");
    // printArray(tamanhoVetor, insertionVec);
    printf("Insertion sort demorou: %f segundos", tempoInsertion);
    printf("\n");


	// quick sort
    int quickVec[tamanhoVetor];
	copia(vetor, quickVec, tamanhoVetor);

    printf("\nQuick sort: ");
    clock_t inicioQuick = clock();    
	quickSort(quickVec, 0, tamanhoVetor - 1);
    clock_t fimQuick = clock();
    double tempoQuick = (double)(fimQuick - inicioQuick) / CLOCKS_PER_SEC;

    printf("\nVetor ordenado pelo quick sort: \n");
    // printArray(tamanhoVetor, quickVec);
    printf("Quick sort demorou: %f segundos", tempoQuick);
    printf("\n");

    free(vetor);

	return 0;
}
