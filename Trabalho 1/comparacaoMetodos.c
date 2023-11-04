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


// void bubbleSort(int *A, int size){
//    int i, j;
//    long int contador = 0;   
//     for (i = 0; i < size; i++) {   
//         for (j = i + 1; j < size; j++) {   
//             if (*(A + j) < *(A + i)) {   
//                 swap((A + j), (A + i));  
//                 contador++;
//             } 
//         } 
//     }   

//     printf("Contador de trocas no bubble: %ld\n", contador);

// }

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

    printf("Contador de trocas no bubble: %ld\n", contador);
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

    printf("Contador de trocas no selection: %ld\n", contador);
}

void insertionSort(int *A, int size) {
    int i, chave, j;
    long int contador = 0;
    for (i = 1; i < size; i++) {
        chave = A[i];
        j = i - 1;

        // Mova os elementos de A[0..i-1] que são maiores que chave
        // para uma posição à frente de sua posição atual
        while (j >= 0 && A[j] > chave) {
            swap(&A[j + 1], &A[j]);
            j = j - 1;
            contador++;
        }
        A[j + 1] = chave;
        contador++;
    }
    printf("Contador de trocas no insertion: %ld\n", contador);
}

// void insertionSort(int *A, int size){
//    	int i,j, min;
//     long int contador= 0;
//     for (i = 1; i < size; i++) {   
//         min=A[i];
//         for (j=i; j>=1 && min< A[j-1];j--){
//             A[j]=A[j-1];
//             contador++;
//         }   
//         A[j]=min;
//         contador++;
//     }

//     printf("Contador de trocas no insertion: %ld\n", contador);

// }

int quickSortAux(int *A, int baixo, int alto, long int *contador) {
    int pivo = A[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (A[j] < pivo) {
            i++;
            swap(&A[i], &A[j]);
            (*contador)++;
        }
    }
    swap(&A[i + 1], &A[alto]);
    (*contador)++;
    return (i + 1);
}

void quickSort(int *A, int baixo, int alto, long int *contador) {
    if (baixo < alto) {
        int indicePivo = quickSortAux(A, baixo, alto, contador);
        quickSort(A, baixo, indicePivo - 1, contador);
        quickSort(A, indicePivo + 1, alto, contador);
    }

}

int main(){

	int i;
	long int tamanhoVetor = 250000;
	int *vetor = (int*)malloc(tamanhoVetor * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < tamanhoVetor; i++){
        vetor[i]=(rand()%tamanhoVetor);
    } 

	printf("\nVetor original: \n");
	printArray(tamanhoVetor, vetor);

	printf("\nVetor tamanho = %ld\n", tamanhoVetor);

	// bubble sort
	int *bubbleVec = (int*)malloc(tamanhoVetor * sizeof(int));
    copia(vetor, bubbleVec, tamanhoVetor);

    printf("\nBubble sort: \n");
    clock_t inicioBubble = clock();    
    bubbleSort(bubbleVec, tamanhoVetor);
    clock_t fimBubble = clock();
    double tempoBubble = ((double)(fimBubble - inicioBubble) / CLOCKS_PER_SEC)/60;
    printf("\nVetor ordenado pelo bubble sort: \n");
    // printArray(tamanhoVetor, bubbleVec);
    printf("Bubble sort demorou: %f minutos", tempoBubble);
    printf("\n");
    

	// selection sort
    int *selectionVec = (int*)malloc(tamanhoVetor * sizeof(int));
	copia(vetor, selectionVec, tamanhoVetor);

    printf("\nSelection sort: \n");
    clock_t inicioSelection = clock();    
	selectionSort(selectionVec, tamanhoVetor);
    clock_t fimSelection = clock();
    double tempoSelection = ((double)(fimSelection - inicioSelection) / CLOCKS_PER_SEC)/60;
    printf("\nVetor ordenado pelo selection sort: \n");
    // printArray(tamanhoVetor, selectionVec);
    printf("Selection sort demorou: %f minutos", tempoSelection);
    printf("\n");


	// insertion sort
    int *insertionVec = (int*)malloc(tamanhoVetor * sizeof(int));
	copia(vetor, insertionVec, tamanhoVetor);

    printf("\nInsertion sort: \n");
    clock_t inicioInsertion = clock();    
	insertionSort(insertionVec, tamanhoVetor);
    clock_t fimInsertion = clock();
    double tempoInsertion = ((double)(fimInsertion - inicioInsertion) / CLOCKS_PER_SEC)/60;
    printf("\nVetor ordenado pelo insertion sort: \n");
    // printArray(tamanhoVetor, insertionVec);
    printf("Insertion sort demorou: %f minutos", tempoInsertion);
    printf("\n");


	// quick sort
    int *quickVec = (int*)malloc(tamanhoVetor * sizeof(int));
    long int contadorQuick = 0;

	copia(vetor, quickVec, tamanhoVetor);
    printf("\nQuick sort: ");
    clock_t inicioQuick = clock();    
	quickSort(quickVec, 0, tamanhoVetor - 1, &contadorQuick);
    clock_t fimQuick = clock();
    double tempoQuick = ((double)(fimQuick - inicioQuick) / CLOCKS_PER_SEC)/60;
    printf("Contador de trocas no quick: %ld\n", contadorQuick);
    printf("\nVetor ordenado pelo quick sort: \n");
    // printArray(tamanhoVetor, quickVec);
    printf("Quick sort demorou: %f minutos", tempoQuick);
    printf("\n");

    free(vetor);
    free(bubbleVec);
    free(selectionVec);
    free(insertionVec);
    free(quickVec);

	return 0;
}



