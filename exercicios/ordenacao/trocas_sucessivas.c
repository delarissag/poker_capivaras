#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void trocas_sucessivas(int n, int v[]) {
    int i, j;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                troca(&v[j], &v[j + 1]);
            }
        }
    }
}

void gerar_vetor(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
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

     gerar_vetor(n, v);

     printf("Vetor antes da ordenacao:\n");
    imprimir_vetor(n, v);

    trocas_sucessivas(n, v);

    printf("Vetor apos a ordenacao:\n");
    imprimir_vetor(n, v);

    free(v);
    return 0;
}
