#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Questão 1
void vetorEmArquivo() {
    FILE *arquivo;
    int vetor[10], i;

    for (i = 0; i < 10; i++) {
        vetor[i] = i + 1;
    }

    arquivo = fopen("questao1.txt", "w");

    for (i = 0; i < 10; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
}

// Questão 2
void vetorRandomicoEmArquivo(){
    FILE *arquivo;
    int vetor[500], i;

    srand(time(NULL));
    for (i = 0; i < 500; i++){
        vetor[i]=(rand()%500);
    } 

    arquivo = fopen("questao2.txt", "w");

    for (int i = 0; i < 500; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
}

// Questão 3
void removerMaioresQueMedia(char *nomeArquivo) {
    FILE *arquivo;
    int vetor[500];
    int i;
    float soma = 0;

    arquivo = fopen(nomeArquivo, "r");
    
    while (fscanf(arquivo, "%d", &vetor[500]) == 1) {
        soma += vetor[500];
    }

    float media = soma / 500;

    int j = 0;
    for (i = 0; i < 500; i++) {
        if (vetor[i] <= media) {
            vetor[j] = vetor[i];
            j++;
        }
    }

    arquivo = fopen(nomeArquivo, "w");

    for (int i = 0; i < j; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);

}

// Questão 4
void textoEmArquivo(){
    FILE *arquivo;
    arquivo = fopen("questao4.txt", "w");

    fprintf(arquivo, "%s\n", "Eu sei trabalhar com arquivos em C");
   
    fclose(arquivo);
}

// Questão 5
void substituirTextoNoArquivo(char *nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r+");

    fseek(arquivo, -(5 * sizeof(char)), SEEK_END);
    fputs("em todas as linguagens de programação", arquivo);
    
    fclose(arquivo);
}

// Questão 6
void adicionarStringNoArquivo(char *nomeArquivo) {
    FILE *arquivo;
    char textoOriginal[100]; 

    arquivo = fopen(nomeArquivo, "r+");

    
        fgets(textoOriginal, sizeof(textoOriginal), arquivo);

        char *posicao = strstr(textoOriginal, "em");

        fseek(arquivo, posicao - textoOriginal + 2, SEEK_SET);

        fputc(' ', arquivo);
        fputs("quase", arquivo);
        fputs(posicao + 2, arquivo);

        fclose(arquivo);
        printf("Texto adicionado com sucesso.\n");
       
        printf("Palavra 'em' não encontrada no arquivo.\n");
        fclose(arquivo);
       
}

void main() {
    // Questão 1
    vetorEmArquivo();

    // Questão 2
    vetorRandomicoEmArquivo();

    // Questão 3
    removerMaioresQueMedia("questao2.txt");

    // Questão 4
    textoEmArquivo();

    // Questão 5
    substituirTextoNoArquivo("questao4.txt");

    // Questão 6
    adicionarStringNoArquivo("questao4.txt");
}
