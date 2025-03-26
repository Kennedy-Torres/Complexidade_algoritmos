#include <stdio.h>
#include <stdlib.h>

// Função para calcular e imprimir a transposta de uma matriz 4x4 com complexidade O(n)
void transposta_o_n(int matriz[4][4]) {// funcão do algoritmo = T(n) =  19n + 228 = O(n)  ----<<-- PIOR CASO = MELHOR CASO 

    // Imprime a matriz original (opcional, para visualização)
    // ======================================================================================| PIOR CASO                ---|==================  MELHOR CASO
    int i, j, k, temp;// --------------------------------------------------------------------|----------  4             ---|------------------   4
    printf("Matriz original:\n"); // --------------------------------------------------------|----------  1             ---|------------------   1 
    for (i = 0; i < 4; i++) { // --------------- 4 iterações (linha) ------------------------|----------  3.(4) = 12    ---|------------------  3.(4) = 12
        for (j = 0; j < 4; j++) { // ----------- 4 iterações (coluna) => Total: 4x4 = 16 ----|----------  3.(16) = 48   ---|------------------  3.(16) = 48
            printf("%d ", matriz[i][j]); // --- Impressão de cada elemento ------------------|----------  3.(16) = 48   ---|------------------  3.(16) = 48
        }
        printf("\n"); // ---------------------- Nova linha após cada linha da matriz --------|----------  4             ---|------------------  4
    }

    // Calcula o n = "número total de elementos na matriz"                                   |
    int n = 4 * 4; // n = 16                                                                 |----------- 1          ------|-------- 1
    // Loop para iterar sobre todos os elementos da matriz garantindo O(n)                   |
    // Como a matriz tem 16 elementos, iteramos de 0 a 15 (n=16)                             |
    for (k = 0; k < n; k++) { // --------- O(n), pois percorre cada elemento apenas uma vez  |----------- 3.n -------------|-------- 3.n
        
        // Calcula os índices (i, j) a partir do índice linear k                             |
        i = k / 4; // ------------------------- Obtém a linha correspondente ao índice k ----|----------- 2.n ------------ |-------- 2.n 
        j = k % 4; // ------------------------- Obtém a coluna correspondente ao índice k ---|----------- 2.n ------------ |-------- 2.n

        // Troca os elementos matriz[i][j] e matriz[j][i] apenas se i < j                    |
        // Isso evita trocas desnecessárias e repetidas                                      | 
        if (i < j) { // ------------------------ A condição evita repetir trocas já feitas   |----------- 1.n -------------|---- 1.n
            temp = matriz[i][j]; // ------------ Armazena temporariamente matriz[i][j]       |----------- 3.n -------------|---- 3.n
            matriz[i][j] = matriz[j][i]; // ---- Atribui matriz[j][i] a matriz[i][j]         |----------- 5.n -------------|---- 5.n
            matriz[j][i] = temp; // ------------ Conclui a troca com a variável temporária   |----------- 3.n -------------|---- 3.n 
        }
    }

    // Imprime a matriz transposta
    printf("\nMatriz transposta:\n");//                                                     |----------- 1 ----------------|---- 1
    for (i = 0; i < 4; i++) { // --------------- 4 iterações (linha)                        |----------- 3.(4)= 12 --------|---- 3.4= 12
        for (j = 0; j < 4; j++) { // ----------- 4 iterações (coluna) => Total: 4x4 = 16    |----------- 3.(16)= 48 -------|---- 3.(16)= 48
            printf("%d ", matriz[i][j]); // --- Impressão de cada elemento da matriz transposta|-------- 3.(16)= 48 -------|---- 3.(16)= 48
        }
        printf("\n"); // ---------------------- Nova linha após cada linha da matriz        |----------- 1 ----------------|---- 1
    }
}

    
int main() { // função main = T(n) = 19n + 389 = O(n)----<<-- PIOR CASO = MELHOR CASO
    // ====================================================================================| PIOR CASO                ---|==================  MELHOR CASO
    int matriz[4][4];  // -----------------------------------------------------------------| ---------- 1             ---|------------------   1
    int i, j;          // -----------------------------------------------------------------| ---------- 2             ---|------------------   2

    // Leitura da matriz do usuário
    printf("Digite os elementos da matriz 4x4:\n");// -------------------------------------| ---------- 1             ---|------------------   1
    for (i = 0; i < 4; i++) { // -------------- 4 iterações (linha)------------------------| ---------- 3.(4)= 12     ---|------------------   3.(4)= 12
        for (j = 0; j < 4; j++) { // ---------- 4 iterações (coluna) => Total: 4x4 = 16   -| ---------- 3.(16)=48     ---|------------------   3.(16)= 48
            printf("Elemento [%d][%d]: ", i, j); // Solicita o valor do elemento [i][j]   -| ---------- 3.(16)=48     ---|------------------   3.(16)= 48
            scanf("%d", &matriz[i][j]); // ---- Armazena o valor digitado na matriz       -| ---------- 3.(16)=48     ---|------------------   3.(16)= 48
        }
    }

    // Chama a função para calcular e imprimir a transposta
    transposta_o_n(matriz);// ------------------------------------------------------------ |---  19n + 228            ---|------------------   19n + 228 

    return 0;       // --------------------------------------------------------------------| ---------- 1             ---|------------------   1
}



/*
Loop Único:
-O algoritmo foi projetado para iterar sobre todos os elementos da matriz usando um único loop, independentemente da ordem dos elementos na matriz original.
-Isso significa que o número de operações realizadas pelo algoritmo é diretamente proporcional ao número de elementos na matriz, que é "n".


Para esse programa Não há cenários em que o algoritmo execute mais ou menos operações significativamente, portanto, o pior e o melhor caso têm a mesma complexidade.
Justificativa: não fizemos validação para verificar se a matriz original teria os mesmos elementos que sua transposta
*/