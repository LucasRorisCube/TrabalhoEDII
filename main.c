#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void teste_tempo( void (*f)(lista*, long), lista* lista, double proporcao){
    
    for(long j = 1000;j<=TAM;j*=10){

        clock_t soma_tempos_aleatorio = 0;
        clock_t soma_tempos_crescente = 0;
        clock_t soma_tempos_decrescente = 0;
        for(int r = 0; r < REPS; r++){

            for(int i = 0;i<j;i++){
                insere_lista(lista, rand()%j);
            }

            clock_t tempo_ini = 0;
            
            // Ordenando com elementos aleatórios
            tempo_ini = clock();
            f(lista,lista->tam * proporcao);
            soma_tempos_aleatorio += clock() - tempo_ini;

            // Ordenando uma lista ordenada em ordem crescente
            tempo_ini = clock();
            f(lista,lista->tam * proporcao);
            soma_tempos_crescente += clock() - tempo_ini;
            
            // Ordenando uma lista ordenada em ordem decrescente
            bubble_sort_inverso(lista,lista->tam * proporcao);
            tempo_ini = clock();
            f(lista,lista->tam * proporcao);
            soma_tempos_decrescente += clock() - tempo_ini;
            
            zera_lista(lista);
        }
        printf("Tempo gasto para ordenar %ld elementos aleatorios: %lf\n",j,((soma_tempos_aleatorio/(double)REPS))/(CLOCKS_PER_SEC));
        printf("Tempo gasto para ordenar %ld elementos ordenados em ordem crescente: %lf\n",j,((soma_tempos_crescente/(double)REPS))/(CLOCKS_PER_SEC));
        printf("Tempo gasto para ordenar %ld elementos ordenados em ordem decrescente: %lf\n",j,((soma_tempos_decrescente/(double)REPS))/(CLOCKS_PER_SEC));
    }
}

int main()
{
    srand(time(NULL));
    lista* lista = cria_lista();
    
    printf("TESTANDO O ALGORITMO BUBBLESORT\n");
    //teste_tempo(bubble_sort,lista,1);

    printf("\nTESTANDO O ALGORITMO BUBBLESORT OTIMIZADO\n");
    //teste_tempo(bubble_sort_otimizado,lista,1);

    printf("\nTESTANDO O ALGORITMO RADIXSORT\n");
    teste_tempo(radix_sort,lista,1);
    
    
    destroi_lista(lista);
}