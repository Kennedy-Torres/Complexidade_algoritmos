#include <stdio.h>
#include <stdlib.h>

//#include "funcao_medida_tempo.c"

void troca(int *vetor, int valor1, int valor2)
{

  int auxiliar = vetor[valor1];
  vetor[valor1] = vetor[valor2];
  vetor[valor2] = auxiliar;
}

int particionar(int *vetor, int inicio, int fim)
{
  int pivo = 0;
  int pivoIndice = 0;
  int i = 0;

  pivo = vetor[fim];
  pivoIndice = inicio;
  for (i = inicio; i < fim; i++)
  {

    if (vetor[i] <= pivo)
    {

      troca(vetor, i, pivoIndice);
      pivoIndice++;
    }
  }

  troca(vetor, pivoIndice, fim);

  return pivoIndice;
}

int particionamentoAleatorio(int *vetor, int inicio, int fim)
{

  int pivoIndice = (rand() % (fim - inicio + 1)) + inicio;

  troca(vetor, pivoIndice, fim);

  return particionar(vetor, inicio, fim);
}

void quickSort(int *vetor, int inicio, int fim)
{
  if (inicio < fim)
  {

    int pivoIndice = particionamentoAleatorio(vetor, inicio, fim);

    quickSort(vetor, inicio, pivoIndice - 1);
    quickSort(vetor, pivoIndice + 1, fim);
  }

}

/*
wrapper (função intermediária) para adaptar o quicksort à assinatura esperada pela função medir_tempo_execucao. O wrapper encapsula a lógica do quicksort e ajusta os parâmetros para que ele possa ser chamado com apenas o vetor e seu tamanho.
*/
// Wrapper para o QuickSort
void quicksort_wrapper(int *arr, int n) {
  quickSort(arr, 0, n - 1);
}

/*
int main()
{
  
  //int vetor[16] = {1, 3, 2, 8, 3, 4, 6, 5, 9, 10, 7, 55, 11, 22, 66, 65};
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
  printf("....continua");

  double tempo_gasto_quickSort = medir_tempo_execucao(quicksort_wrapper, vetor, 100000);
  //quickSort(vetor, 0, 9);


  printf("\n\nvetor ordenado\n");
  for (int i = 0; i < 16; i++)
  {
    printf("[%d] ", vetor[i]);
  }
  printf("....continua");
  
  //getchar();

  printf("\nQuickSort: Tempo decorrido %lf segundos\n", tempo_gasto_quickSort);
  return 0;
}
*/