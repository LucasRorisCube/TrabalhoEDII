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