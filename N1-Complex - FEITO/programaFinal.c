#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubbleSort.c"
#include "mergeSort.c"
#include "quickSort.c"
#include "funcao_medida_tempo.c"

// Função para preencher um vetor com valores aleatórios
void preencher_vetor_aleatorio(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10000; // Valores aleatórios entre 0 e 9999
    }
}

int main() {
    // Tamanhos dos vetores
    int tamanhos[] = {100, 300, 500, 1000, 10000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Semente para números aleatórios
    srand((unsigned int)time(NULL));

    // Criação do arquivo CSV
    FILE *arquivo = fopen("resultados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de resultados.\n");
        return 1;
    }
    fprintf(arquivo, "Tamanho,BubbleSort,MergeSort,QuickSort\n");

    // Loop para cada tamanho de vetor
    for (int t = 0; t < num_tamanhos; t++) {
        int tamanho = tamanhos[t];
        int vetor[tamanho];
        int vetor_copia[tamanho];

        // Preenche o vetor com valores aleatórios
        preencher_vetor_aleatorio(vetor, tamanho);

        printf("\n--- Resultados para vetor de tamanho %d ---\n", tamanho);

        // BubbleSort
        for (int i = 0; i < tamanho; i++) vetor_copia[i] = vetor[i]; // Copia o vetor original
        double tempo_bubble = medir_tempo_execucao(bubbleSort, vetor_copia, tamanho);
        printf("BubbleSort: %.12f microsegundos\n", tempo_bubble);

        // MergeSort
        for (int i = 0; i < tamanho; i++) vetor_copia[i] = vetor[i]; // Copia o vetor original
        double tempo_merge = medir_tempo_execucao(mergeSort, vetor_copia, tamanho);
        printf("MergeSort: %.12f microsegundos\n", tempo_merge);

        // QuickSort
        for (int i = 0; i < tamanho; i++) vetor_copia[i] = vetor[i]; // Copia o vetor original
        double tempo_quick = medir_tempo_execucao(quicksort_wrapper, vetor_copia, tamanho);
        printf("QuickSort: %.12f microsegundos\n", tempo_quick);

        // Salva os resultados no arquivo CSV
        fprintf(arquivo, "%d,%.12f,%.12f,%.12f\n", tamanho, tempo_bubble, tempo_merge, tempo_quick);
    }

    fclose(arquivo);
    printf("\nResultados salvos em 'resultados.csv'.\n");

    return 0;
}