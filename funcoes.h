#define TAM 100000
#define REPS 10

typedef int elem;

typedef struct{
    elem *elementos;
    long tam;
}lista;

lista* cria_lista();
void destroi_lista(lista* lista);
void zera_lista(lista* lista);
void print_lista(lista* lista);
void insere_lista(lista* lista, elem num);
void bubble_sort(lista* lista, long final);
void bubble_sort_otimizado(lista* lista, long final);
void bubble_sort_inverso(lista* lista, long final);
void radix_sort(lista* lista, long final);
void counting_sort(lista* lista, long final, long posicao);