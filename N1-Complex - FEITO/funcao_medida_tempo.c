
/*
O Que Esse Código Faz?
Este código mede o tempo necessário para executar um loop de 100 milhões de iterações. Ele utiliza a função clock() para capturar o tempo antes e depois do loop e calcula a diferença entre esses dois tempos.
*/
#include <time.h>
#include <stdio.h>




  

// VAMOS PASSAR O ALGORITMO QUE QUEREMOS MEDIR O TEMPO, O VETOR E O TAMANHO DO VETOR
/*
double medir_tempo_execucao(void (*algoritmo)(int[], int), int *vetor, int tamanho)
{
    clock_t tempo_inicial, tempo_final;
    // Captura o tempo inicial   
    tempo_inicial = clock();

    // Executa o algoritmo de ordenação
    algoritmo(vetor, tamanho);

    // Captura o tempo final  
    tempo_final = clock(); 
    //for (int i = 0; i < 10000000; i++); //alteração necessária para que a função de tempo retorne um valor representativo

    double tempo_decorrido = (tempo_final - tempo_inicial)/(double)CLOCKS_PER_SEC;
    
    //return timedif*1000000; // Retorna o tempo em microsegundos
    return tempo_decorrido*1000000; // Retorna o tempo em microsegundos
}
*/

/*
double medir_tempo_execucao(void (*func)(int *, int), int *vetor, int tamanho) {
    int repeticoes = 400; // Número de repetições para melhorar a precisão
    clock_t inicio, fim;
    double tempo_total = 0.0;

    for (int i = 0; i < repeticoes; i++) {
        // Cria uma cópia do vetor original para cada execução
        int vetor_copia[tamanho];
        for (int j = 0; j < tamanho; j++) {
            vetor_copia[j] = vetor[j];
        }

        // Mede o tempo de execução
        inicio = clock();
        func(vetor_copia, tamanho);
        fim = clock();

        tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    // Retorna o tempo médio por execução
    return tempo_total / repeticoes;
}
*/

double medir_tempo_execucao(void (*func)(int *, int), int *vetor, int tamanho) {
    clock_t inicio, fim;
    double tempo_total = 0.0;

    // Cria uma cópia do vetor original para cada execução
    int vetor_copia[tamanho];
    for (int j = 0; j < tamanho; j++) {
        vetor_copia[j] = vetor[j];
    }

    // Mede o tempo de execução
    inicio = clock();
    func(vetor_copia, tamanho);
    for(int i = 0; i < 100000000; i++); //alteração necessária para que a função de tempo retorne um valor representativo para o ser humano
    fim = clock();

    tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempo_total*1000000; // Retorna o tempo em microsegundos
}