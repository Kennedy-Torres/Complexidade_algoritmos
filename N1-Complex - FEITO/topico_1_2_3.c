/*
ENUNCIADO:
    1. Incluir a função de medida de tempo em cada código. 
    2. Executar os três códigos para o mesmo vetor. Faça a alteração necessária 
    para que a função de tempo retorne um valor representativo para o ser 
    humano. 
    3. Anotar o tempo do item dois na execução de cada ordenador.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

#include "bubbleSort.c"
#include "mergeSort.c"
#include "quickSort.c"
#include "funcao_medida_tempo.c"

int main()
{
    clock_t tempo_inicial, tempo_final;
    int vetor[10] = {1, 3, 2, 8, 3, 4, 6, 5, 9, 10};

    printf("\nVetor antes da ordenacao\n");
    for (int i = 0; i < 10; i++)
    {
        printf("[%d] ", vetor[i]);
    }

    double tempo_gasto_bubbleSort = medir_tempo_execucao(bubbleSort, vetor, 10);
    double tempo_gasto_quickSort = medir_tempo_execucao(quicksort_wrapper, vetor, 10);
    double tempo_gasto_mergeSort = medir_tempo_execucao(mergeSort, vetor, 10);

    printf("\n\nVetor ordenado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("[%d] ", vetor[i]);
    }

    printf("\n\nBubbleSort: Tempo decorrido %lf microsegundos\n", tempo_gasto_bubbleSort);
    printf("\nMergeSort: Tempo decorrido %lf microsegundos\n", tempo_gasto_mergeSort);
    printf("\nQuickSort: Tempo decorrido %lf microsegundos\n", tempo_gasto_quickSort);

    return 0;
}