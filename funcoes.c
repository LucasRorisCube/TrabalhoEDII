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