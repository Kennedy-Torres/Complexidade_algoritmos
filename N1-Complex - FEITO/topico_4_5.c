/*
ENUNCIADO:
    4. Criar um código que randomize cinco vetores com 100, 300, 500, 1000 e 
    10000 elementos. 
    5. Para cada vetor randomizado, execute os ordenadores e anote os 
    resultados. Neste item também é necessário fazer a alteração descrita no 
    item dois.
*/

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
        printf("BubbleSort: %.12f segundos\n", tempo_bubble);

        // MergeSort
        for (int i = 0; i < tamanho; i++) vetor_copia[i] = vetor[i]; // Copia o vetor original
        double tempo_merge = medir_tempo_execucao(mergeSort, vetor_copia, tamanho);
        printf("MergeSort: %.12f segundos\n", tempo_merge);

        // QuickSort
        for (int i = 0; i < tamanho; i++) vetor_copia[i] = vetor[i]; // Copia o vetor original
        double tempo_quick = medir_tempo_execucao(quicksort_wrapper, vetor_copia, tamanho);
        printf("QuickSort: %.12f segundos\n", tempo_quick);
    }

    return 0;
}