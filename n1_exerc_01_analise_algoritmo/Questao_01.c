#include <stdio.h>
#include <stdlib.h>

// USEI Selection Sort para ordenar o vetor- SUA COMPLEXIDADE É O(n^2)
void selection_Sort(int *vetor, int tamanho) { // T(n) = (3n - 3) + 7n^2 - 7n = 7n^2 -4n - 3 = O(n^2) ----<<---- PIOR CASO   -------- 
                                             //T(n) = (3n - 3) +  5n^2 - 5n = 5n^2 -2n - 3 = O(n^2)   ----<<---- MELHOR CASO -------- 

                                                                        //   ----------------------------- PIOR CASO --------------------- MELHOR CASO
    for (int i = 0/*c1*/; i < tamanho - 1/*c2*/; i++/*c3*/) {           //    ----loop externo------------ 3 . (n - 1)    ---------------- 3 . (n - 1)
        for (int j =/*c4*/ i + 1/*c5*/; j < tamanho/*c6*/; j++/*c7*/) { // ---loop interno---------------- 4 . [n(n-1)/2] ---------------- 4 . [n(n-1)/2]
            if (vetor[i]/*c8*/ >/*c9*/ vetor[j]/*c10*/) {               // ---------interno--------------- 3 . [n(n-1)/2] ---------------- 3 . [n(n-1)/2]
                
                int temp =/*c11*/ vetor[i]/*c12*/;                      // ---------interno--------------- 2 . [n(n-1)/2] ---------------- 0 
                vetor[i]/*c13*/ =/*c14*/ vetor[j]/*c15*/;               // ---------interno--------------- 3 . [n(n-1)/2] ---------------- 0
                vetor[j]/*c16*/ =/*c17*/ temp;                          // ---------interno--------------- 2 . [n(n-1)/2] ---------------- 0
            }
        }
    }
}

//func. p/ copiar os elementos de um vetor para outro e ordená-los em ordem crescente ---- notação “big-O” = O(n^2) para pior e melhor caso  ##!!!!!!!!
void copiar_em_ordem_crescente(int *origem, int *destino, int tamanho) { // T(n) = 7n^2 +4n - 3 ----<<-- PIOR CASO      
                                                                         // T(n) = 5n^2 +6n - 3 ----<<-- MELHOR CASO    

    // ----------------------------------------------------------------------------------------- PIOR CASO ------------------  MELHOR CASO
    for (int i = 0/*c1*/; i </*c2*/ tamanho; i++/*c3*/) {  // ---------------------------------- 3.(n) ----------------------  3.(n)
        // Copia os valores de origem para destino 
        destino[i]/*c4*/ =/*c5*/ origem[i]/*c6*/;   // ----------------------------------------- 3.(n) ----------------------  3.(n)
        // substitui os valores do vetor origem p/ -1
        origem[i]/*c7*/ =/*c8*/ -1;           // ----------------------------------------------- 2.(n) ----------------------  2.(n)
    }
    selection_Sort(destino, tamanho); // Ordena o vetor destino -------------------------------  7n^2 -4n - 3  --------------  5n^2 -2n - 3
}

void exibir_vetor(int *vetor, int tamanho) {// T(n) = 5n + 1 = O(n) ----<<--- PIOR CASO = MELHOR CASO 
    // --------------------------------------------------------------------------------  PIOR CASO    -----------------  MELHOR CASO
    for (int i = 0/*c1*/; i < tamanho/*c2*/; i++/*c3*/) {// -------------------------    3.(n)      -------------------  3.(n)
        printf/*c4*/("%d ", vetor[i]/*c5*/); // -------------------------------------    2.(n)      -------------------  2.(n)
    }
    printf/*c6*/("\n"); // ------------------------------------------------------------    1        -------------------  1
}

int main() {// função main = T(n) = 7n^2 + 19n + 11 = O(n^2)----<<--- PIOR CASO       
            // função main = T(n) = 5n^2 + 21n + 11 = O(n^2)----<<--- MELHOR CASO     
    // ----------------------------------------------------------------------------------------------- PIOR CASO ------------------ MELHOR CASO
    int vetor_origem[] = {5, 2, 8, 3, 1};  // Exemplo de vetor de origem com 5 atribuições) ----------    5      ------------------    5     
    int tamanho = 5; // ------------------------------------------------------------------------------    1      ------------------    1
    int vetor_destino[tamanho];  // ---------------------------------------------- -------------------    1      ------------------    1

    printf("Vetor de origem inicial:\n"); // ---------------------------------------------------------    1      ------------------    1
    exibir_vetor(vetor_origem, tamanho); //  --------------------------------------------------------- 5n + 1    ------------------  5n + 1
    
    copiar_em_ordem_crescente(vetor_origem, vetor_destino, tamanho); // ------------------------- 7n^2 +4n - 3   ------------------ 5n^2 +6n - 3
    
    printf("\nVetor de destino ordenado:\n"); // -----------------------------------------------------    1      ------------------    1
    exibir_vetor(vetor_destino, tamanho);//  --------------------------------------------------------- 5n + 1    ------------------  5n + 1

    printf("\nVetor de origem depois da copia:\n"); // -----------------------------------------------    1      ------------------    1
    exibir_vetor(vetor_origem, tamanho);//  ---------------------------------------------------------- 5n + 1    ------------------  5n + 1

    return 0; // -------------------------------------------------------------------------------------    1      ------------------    1
}


/*

[12, 8, 5, 2]
n = 4
i = 0 ; j= 1;2;3
i = 1 ; j= 2;3
i = 2 ; j= 3;
i = 3 NÃO ENTRA NO LOOP --- LOOP EXTERNO RODA n-1 vezes

ORIGINAL = [12, 8, 5, 2]
i=0; j= 1 ---if (12 > 8) ---- [8, 12, 5, 2]
i=0; j= 2 ---if (8 > 5) ----- [5, 12, 8, 2]
i=0; j= 3 ---if (5 > 2) ----- [2, 12, 8, 5]
para i=0 temos  LOOP INTERNO RODA n-1 vezes
----

i=1; j= 2 ---if (12 > 8) ----- [2, 8, 12, 5] 
i=1; j= 3 ---if (8 > 5) ------ [2, 5, 12, 8]
para i=1 temos LOOP INTERNO RODA n-2 vezes
----
i=2; j= 3 ---if (12 > 8) ----- [2, 5, 8, 12] 
para i=2 temos LOOP INTERNO RODA n-3 vezes 
----
PORTANTO O LOOP INTERNO REALIZA UMA PA DE RAZÃO IGUAL A n - 1; primeiro termo 1; ultimo termo n-1 ------ LOGO TEMOS ((n-1)(1+[n-1]))/2 = ((n-1)(n))/2 = (n^2 - n)/2



n=4
(n^2 - n)/2 = (16 - 4)/2 = 6
*/