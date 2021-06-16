#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

lista* cria_lista(){
    
    lista* lista;
    lista = malloc(sizeof(lista));
    lista->elementos = malloc(sizeof(elem)*TAM);
    lista->tam = 0;
    return lista;

}

void destroi_lista(lista* lista){
    free(lista->elementos);
    free(lista);
}

void zera_lista(lista* lista){
    free(lista->elementos);
    lista->elementos = malloc(sizeof(elem)*TAM);
    lista->tam = 0;
}

void insere_lista(lista* lista, elem num){
    lista->elementos[lista->tam] = num;
    (lista->tam) += 1;
}

void print_lista(lista* lista){
    for(long i = 0;i<lista->tam;i++){

        printf("%d ",lista->elementos[i]);

    }
    printf("\n");
}

void bubble_sort(lista* lista, long final){

    for(long i = 0; i<final-1;i++){
        for(long j = 0; j<final-i-1;j++){
            if(lista->elementos[j] > lista->elementos[j+1]){
                elem temp = lista->elementos[j];
                lista->elementos[j] = lista->elementos[j+1];
                lista->elementos[j+1] = temp;
            }
        }
    }
}

void bubble_sort_otimizado(lista* lista, long final){
    
    for(long i = 0; i<final-1;i++){
        int ordenado = 1;
        for(long j = 0; j<final-i-1;j++){
            if(lista->elementos[j] > lista->elementos[j+1]){
                elem temp = lista->elementos[j];
                lista->elementos[j] = lista->elementos[j+1];
                lista->elementos[j+1] = temp;
                ordenado = 0;
            }
        }
        if(ordenado) break;
    }
}

void bubble_sort_inverso(lista* lista, long final){

    for(long i = 0; i<final-1;i++){
        for(long j = 0; j<final-i-1;j++){
            if(lista->elementos[j] < lista->elementos[j+1]){
                elem temp = lista->elementos[j];
                lista->elementos[j] = lista->elementos[j+1];
                lista->elementos[j+1] = temp;
            }
        }
    }
}

long partition(lista* lista, long inicio, long final){
    long pivo = lista->elementos[final];
    long i = inicio-1;
    elem tmp;
    for(long j = inicio; j < final;j++){
        if(lista->elementos[j] <= pivo){
            i = i+1;
            tmp = lista->elementos[j];
            lista->elementos[j] = lista->elementos[i];
            lista->elementos[i] = tmp;
        }
    }
    tmp = lista->elementos[i+1];
    lista->elementos[i+1] = lista->elementos[final];
    lista->elementos[final] = tmp;
    return (i+1);
}

long random_partition(lista* lista, long inicio, long final){
    long k = inicio + rand()%(final-inicio);
    elem tmp = lista->elementos[k];
    lista->elementos[k] = lista->elementos[final];
    lista->elementos[final] = tmp;
    return partition(lista,inicio,final);
}

void quick_sort(lista* lista, long inicio, long final){
    if(inicio < final){
        long pivo = random_partition(lista,inicio,final);
        quick_sort(lista,inicio,pivo-1);
        quick_sort(lista,pivo+1,final);
    }
}

void chamada_quick_sort(lista* lista, long final){
    quick_sort(lista,0,final-1);
}




void radix_sort(lista* lista, long final){
    elem maior = 0;
    for(int i = 0;i < final;i++){
        if(lista->elementos[i] > maior){
            maior = lista->elementos[i];
        }
    }
    long posicao = 1;
    while(maior/posicao > 0){
        counting_sort(lista,final,posicao);
        posicao *= 10;
    }
}

void counting_sort(lista* list, long final, long posicao){

    lista* B = cria_lista();
    long i;
    for(i = 0;i < 10;i++){
        insere_lista(B,0);
    }
    long chave;
    for(i = 0;i <= final-1;i++){
        chave = list->elementos[i]/posicao;
        chave = chave%10;
        B->elementos[chave] = B->elementos[chave] + 1;
    }
    for(i = 1;i <= 9;i++){
        B->elementos[i] = B->elementos[i] + B->elementos[i-1];
    }
    lista* C = cria_lista();
    for(i = 0;i < final;i++){
        insere_lista(C,0);
    }
    for(i = final-1;i >= 0;i--){
        chave = list->elementos[i]/posicao;
        chave = chave%10;
        B->elementos[chave] = B->elementos[chave] - 1;
        C->elementos[B->elementos[chave]] = list->elementos[i];
    }
    for(i = 0;i <= final-1;i++){
        list->elementos[i] = C->elementos[i];
    }
}


void heapify(lista* lista,long final,long i){
    long maior = i;
    long esquerda = 2*i + 1;
    long direita = 2*i + 2;
    if(esquerda < final && lista->elementos[esquerda] > lista->elementos[maior]){
        maior = esquerda;
    }
    if(direita < final && lista->elementos[direita] > lista->elementos[maior]){
        maior = direita;
    }
    if (maior != i){
        elem tmp = lista->elementos[i];
        lista->elementos[i] = lista->elementos[maior];
        lista->elementos[maior] = tmp;
        heapify(lista,final,maior);
    }
}

void heap_sort(lista* lista, long final){
    long i;
    
    for(i = (final/2)-1;i >= 0;i--){
        heapify(lista,final,i);
    }
    for(i = final-1;i >= 1;i--){
        elem tmp = lista->elementos[0];
        lista->elementos[0] = lista->elementos[i];
        lista->elementos[i] = tmp;
        heapify(lista,i,0);
    }
}

