#define TAM 1000000
#define REPS 100

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

void quick_sort(lista* lista, long inicio, long final);
long random_partition(lista* lista, long inicio, long final);
long partition(lista* lista, long inicio, long final);
void chamada_quick_sort(lista* lista, long final);

void radix_sort(lista* lista, long final);
void counting_sort(lista* lista, long final, long posicao);

void heap_sort(lista* lista, long final);
void heapify(lista* lista,long final,long i);