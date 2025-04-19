#include <stdio.h>
#include <stdlib.h>

//#include "funcao_medida_tempo.c"

void merge(int *vetor, int tamanho)
{
  int meio = tamanho / 2;
  int i = 0, j = meio, k = 0;
  int auxiliar[tamanho];
  while (i < meio && j < tamanho)
  {
    if (vetor[i] <= vetor[j])
      auxiliar[k] = vetor[i++];
    else
      auxiliar[k] = vetor[j++];
    k++;
  }
  if (i == meio)
    while (j < tamanho)
      auxiliar[k++] = vetor[j++];
  else
    while (i < meio)
      auxiliar[k++] = vetor[i++];
  for (i = 0; i < tamanho; i++)
    vetor[i] = auxiliar[i];

}

void mergeSort(int *vetor, int tamanho)
{
  int meio = tamanho / 2;
  if (tamanho > 1)
  {
    mergeSort(vetor, meio);
    mergeSort(vetor + meio, tamanho - meio);
    merge(vetor, tamanho);
  }
}

// COMPILA SEM TER A FUNÇÃO MAIN: gcc -c .\mergeSort.c -o .\mergeSort.o
/*
int main()
{

  //int vetor[10] = {1, 3, 2, 8, 3, 4, 6, 5, 9, 10};
  int vetor[100000];
  // vetor com valores em ordem decrescente
  for (int i = 0; i < 100000; i++) {
    vetor[i] = 100000 - i;
  }

  printf("\nvetor antes da ordenacao\n");
  for (int i = 0; i < 16; i++)
  {
    printf("[%d] ", vetor[i]);
  }
  

  double tempo_gasto_mergeSort = medir_tempo_execucao(mergeSort, vetor, 100000);


  printf("\n\nvetor ordenado\n");
  for (int i = 0; i < 16; i++)
  {
    printf("[%d] ", vetor[i]);
  }
  
  //getchar();

  printf("\n\nMergeSort: Tempo decorrido %lf segundos\n", tempo_gasto_mergeSort);
  return 0;
}
*/