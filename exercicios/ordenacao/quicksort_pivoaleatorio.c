#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int p, int r, int v[MAX])
{
    int x, i, j;
    x = v[p+rand()%(r-p+1)];
    i = p - 1;
    j = r + 1;
    while (i < j) {
        do {
            j--;
        } while (v[j] > x);
        do {
            i++;
        } while (v[i] < x);
        if (i < j)
            troca(&v[i], &v[j]);
    }
    return j;
}


void quicksort(int p, int r, int v[MAX])
{
    int q;
    if (p < r) {
        q = separa(p, r, v);
        quicksort(p, q, v);
        quicksort(q+1, r, v);
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

    quicksort(0, n, v);

    printf("Vetor apos a ordenacao:\n");
    imprimir_vetor(n, v);

    free(v);
    return 0;
}
