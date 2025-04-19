#include <stdio.h>
#include <stdlib.h>

//#include "funcao_medida_tempo.c"

void bubbleSort(int *vetor, int tamanho)
{
  int atual = 0;
  int proximo = 0;
  ;
  int auxiliar = 0;

  for (atual = 1; atual < tamanho; atual++)
  {

    for (proximo = 0; proximo < tamanho - 1; proximo++)
    {

      if (vetor[proximo] > vetor[proximo + 1])
      {
        auxiliar = vetor[proximo];
        vetor[proximo] = vetor[proximo + 1];
        vetor[proximo + 1] = auxiliar;
      }
    }
  }

}

/*
int main()
{

  //int vetor[10] = {1, 3, 2, 8, 3, 4, 6, 5, 9, 10};
  int vetor[100000];
  // vetor com valores em ordem decrescente
  for (int i = 0; i < 100000; i++) {
    vetor[i] = 100000 - i;
  }

  printf("\nVetor antes da ordenacao\n");
  for (int i = 0; i < 16; i++)
  {
    printf("[%d] ", vetor[i]);
  }
  printf("....continua");

  double tempo_gasto_bubbleSort = medir_tempo_execucao(bubbleSort, vetor, 100000);


  printf("\n\nVetor ordenado\n");
  for (int i = 0; i < 16; i++)
  {
    printf("[%d] ", vetor[i]);
  }
  printf("....continua");


  printf("\n\nBubbleSort: Tempo decorrido %lf segundos\n", tempo_gasto_bubbleSort);

  return 0;
}
*/