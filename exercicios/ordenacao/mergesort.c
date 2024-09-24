#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 10 // Tamanho máximo do vetor

void intercala(int p, int q, int r, int v[]) {
    int i, j, k, w[MAX];
    i = p, j = q, k = 0;

    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k] = v[i];i++;
        } else {
            w[k] = v[j];j++;
        }
        k++;
    }

    while (i < q) {
        w[k] = v[i];i++;k++;
    }

    while (j < r) {
        w[k] = v[j];j++;k++;
    }

    for (i = p; i < r; i++) {
        v[i] = w[i - p];
    }
}

void mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
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

    gerar_vetor(n, v);

    printf("Vetor antes da ordenacao:\n");
    imprimir_vetor(n, v);

    mergesort(0, n, v);

    printf("Vetor apos a ordenacao:\n");
    imprimir_vetor(n, v);

    free(v);
    return 0;
}
