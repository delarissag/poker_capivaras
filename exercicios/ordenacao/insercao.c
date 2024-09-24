#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 10 // Tamanho m�ximo do vetor

void insercao(int n, int v[]) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = v[i];
        for (j = i - 1; j >= 0 && v[j] > x; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = x;
    }
}

void gerar_vetor(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100; // N�meros aleat�rios de 0 a 99
    }
}

void imprimir_vetor(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Inicializa a seed para n�meros aleat�rios

    int n = MAX;
    int *v = (int *)malloc(n * sizeof(int));

    gerar_vetor(n, v);

    printf("Vetor antes da ordenacao:\n");
    imprimir_vetor(n, v);

    insercao(n, v);

    printf("Vetor apos a ordenacao:\n");
    imprimir_vetor(n, v);

    free(v);
    return 0;
}
