#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int busca_sequencial_R(int n, int v[MAX], int x)
{
    if (n == 0)
        return -1;
    else
        if (x == v[n - 1])
            return n - 1;
        else
            return busca_sequencial_R(n - 1, v, x);
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
    printf("%d",busca_sequencial_R(n, v, x));

    return 0;
}

