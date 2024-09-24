#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int busca_sequencial(int n, int v[MAX], int x)
{
    int k;
    for (k = n - 1; k >= 0 && v[k] != x; k--)
        ;
    return k;
}

void gerar_vetor(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10;
    }
}

void imprimir_vetor(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Inicializa a seed para números aleatórios

    int n = MAX;
    int *v = (int *)malloc(n * sizeof(int));
    int x;
    gerar_vetor(n, v);


    printf("Vetor imprimir vetor:\n");
    imprimir_vetor(n, v);

    printf("Informe o valor a buscar:\n");
    scanf("%d",&x);

    printf("Indice:\n");
    printf("%d",busca_sequencial(n, v, x));

    return 0;
}

