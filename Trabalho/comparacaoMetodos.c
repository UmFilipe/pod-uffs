/**
 * @file comparacaoMetodos.c
 * @author Eduardo_Pazzini_Zancanaro_e_Filipe_Medeiros_de_Almeida
 * @version 0.2
 * @date 2023-11-17
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

void bubbleSort(int *A, int size) {
    int i, j;
    long int contador = 0;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                contador++;
            }
        }
    }

    printf("Contador de trocas no bubble: %ld", contador);
}

void selectionSort(int *A, int size){
    long int contador = 0;

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

    printf("Contador de trocas no selection: %ld", contador);
}

void insertionSort(int *A, int size) {
    int i, chave, j;
    long int contador = 0;

    for (i = 1; i < size; i++) {
        chave = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > chave) {
            swap(&A[j + 1], &A[j]);
            j = j - 1;
            contador++;
        }

        A[j + 1] = chave;
        contador++;
    }

    printf("Contador de trocas no insertion: %ld", contador);
}

int quickSortAux(int *A, int primeiro, int ultimo, long int *contador) {
    int pivo = A[ultimo];
    int i = (primeiro - 1);

    for (int j = primeiro; j <= ultimo - 1; j++) {
        if (A[j] < pivo) {
            i++;
            swap(&A[i], &A[j]);
            (*contador)++;
        }
    }
    swap(&A[i + 1], &A[ultimo]);
    (*contador)++;
    return (i + 1);
}

void quickSort(int *A, int primeiro, int ultimo, long int *contador) {
    if (primeiro < ultimo) {
        int indicePivo = quickSortAux(A, primeiro, ultimo, contador);
        quickSort(A, primeiro, indicePivo - 1, contador);
        quickSort(A, indicePivo + 1, ultimo, contador);
    }

}

void manterHeapMax(int *A, int size, int i, long int *contador) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < size && A[esquerda] > A[maior]) {
        maior = esquerda;
    }

    if (direita < size && A[direita] > A[maior]) {
        maior = direita;
    }

    if (maior != i) {
        swap(&A[i], &A[maior]);
        (*contador)++;
        manterHeapMax(A, size, maior, contador);
    }
}

void construirHeapMax(int *A, int size, long int *contador) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        manterHeapMax(A, size, i, contador);
    }
}

void heapSort(int *A, int size) {
    long int contador = 0;
    
    construirHeapMax(A, size, &contador);

    for (int i = size - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        contador++;
        manterHeapMax(A, i, 0, &contador);
    }

    printf("Contador de trocas no heap: %ld", contador);
}

void countingSort(int *A, int size, int exp) {
    int arrayTemp[size];
    int arrayContagem[10] = {0};

    for (int i = 0; i < size; i++) {
        arrayContagem[(A[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        arrayContagem[i] += arrayContagem[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        arrayTemp[arrayContagem[(A[i] / exp) % 10] - 1] = A[i];
        arrayContagem[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        if (A[i] != arrayTemp[i]) {
            A[i] = arrayTemp[i];
        }
    }
}

void radixSort(int *A, int size) {
    int max = A[0];
    long int contador = 0;

    for (int i = 1; i < size; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(A, size, exp);
    }

    printf("Contador de trocas no radix: %ld", contador);
}

void main(){

	int i;
	long int tamanhoVetor = 50000;
	int *vetor = (int*)malloc(tamanhoVetor * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < tamanhoVetor; i++){
        vetor[i]=(rand()%tamanhoVetor);
    } 

	printf("\nVetor original: \n");
	// printArray(tamanhoVetor, vetor);

	printf("\nVetor tamanho = %ld\n", tamanhoVetor);

	// bubble sort
	int *bubbleVec = (int*)malloc(tamanhoVetor * sizeof(int));
    copia(vetor, bubbleVec, tamanhoVetor);

    printf("\nBubble sort: \n");
    clock_t inicioBubble = clock();    
    bubbleSort(bubbleVec, tamanhoVetor);
    clock_t fimBubble = clock();
    double tempoBubble = ((double)(fimBubble - inicioBubble) / CLOCKS_PER_SEC);
    printf("\nVetor ordenado pelo bubble sort: \n");
    // printArray(tamanhoVetor, bubbleVec);
    printf("Bubble sort demorou: %f segundos", tempoBubble);
    printf("\n");
    

	// selection sort
    int *selectionVec = (int*)malloc(tamanhoVetor * sizeof(int));
	copia(vetor, selectionVec, tamanhoVetor);

    printf("\nSelection sort: \n");
    clock_t inicioSelection = clock();    
	selectionSort(selectionVec, tamanhoVetor);
    clock_t fimSelection = clock();
    double tempoSelection = ((double)(fimSelection - inicioSelection) / CLOCKS_PER_SEC);
    printf("\nVetor ordenado pelo selection sort: \n");
    // printArray(tamanhoVetor, selectionVec);
    printf("Selection sort demorou: %f segundos", tempoSelection);
    printf("\n");


	// insertion sort
    int *insertionVec = (int*)malloc(tamanhoVetor * sizeof(int));
	copia(vetor, insertionVec, tamanhoVetor);

    printf("\nInsertion sort: \n");
    clock_t inicioInsertion = clock();    
	insertionSort(insertionVec, tamanhoVetor);
    clock_t fimInsertion = clock();
    double tempoInsertion = ((double)(fimInsertion - inicioInsertion) / CLOCKS_PER_SEC);
    printf("\nVetor ordenado pelo insertion sort: \n");
    // printArray(tamanhoVetor, insertionVec);
    printf("Insertion sort demorou: %f segundos", tempoInsertion);
    printf("\n");


	// quick sort
    int *quickVec = (int*)malloc(tamanhoVetor * sizeof(int));
    long int contadorQuick = 0;

	copia(vetor, quickVec, tamanhoVetor);
    printf("\nQuick sort: \n");
    clock_t inicioQuick = clock();    
	quickSort(quickVec, 0, tamanhoVetor - 1, &contadorQuick);
    clock_t fimQuick = clock();
    double tempoQuick = ((double)(fimQuick - inicioQuick) / CLOCKS_PER_SEC);
    printf("Contador de trocas no quick: %ld", contadorQuick);
    printf("\nVetor ordenado pelo quick sort: \n");
    // printArray(tamanhoVetor, quickVec);
    printf("Quick sort demorou: %f segundos", tempoQuick);
    printf("\n");

    // heap sort
    int *heapVec = (int*)malloc(tamanhoVetor * sizeof(int));
    copia(vetor, heapVec, tamanhoVetor);

    printf("\nHeap sort: \n");
    clock_t inicioHeap = clock();
    heapSort(heapVec, tamanhoVetor);
    clock_t fimHeap = clock();
    double tempoHeap = ((double)(fimHeap - inicioHeap) / CLOCKS_PER_SEC);
    printf("\nVetor ordenado pelo heap sort: \n");
    // printArray(tamanhoVetor, heapVec);
    printf("Heap sort demorou: %f segundos", tempoHeap);
    printf("\n");

    // radix sort
    int *radixVec = (int*)malloc(tamanhoVetor * sizeof(int));
    copia(vetor, radixVec, tamanhoVetor);

    printf("\nRadix sort: \n");
    clock_t inicioRadix = clock();
    radixSort(radixVec, tamanhoVetor);
    clock_t fimRadix = clock();
    double tempoRadix = ((double)(fimRadix - inicioRadix) / CLOCKS_PER_SEC);
    printf("\nVetor ordenado pelo radix sort: \n");
    // printArray(tamanhoVetor, radixVec);
    printf("Radix sort demorou: %f segundos", tempoRadix);
    printf("\n");

    free(vetor);
    free(bubbleVec);
    free(selectionVec);
    free(insertionVec);
    free(quickVec);
    free(heapVec);
    free(radixVec);

}



