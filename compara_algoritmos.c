#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

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

void selecao(int n, int v[MAX])
{
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (v[j] < v[min]){
                min = j;
            }
        }
        troca(&v[i], &v[min]);
    }
}

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

void intercala(int p, int q, int r, int v[]) {
    int i = p, j = q, k = 0;
    int *w = (int *)malloc((r - p) * sizeof(int));

    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }

    while (i < q) {
        w[k++] = v[i++];
    }

    while (j < r) {
        w[k++] = v[j++];
    }

    for (i = p; i < r; i++) {
        v[i] = w[i - p];
    }

    free(w);
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
        v[i] = rand() % 100;
    }
}

double medir_tempo(void (*funcao)(int, int[]), int n, int v[]) {
    clock_t inicio = clock();
    funcao(n, v);
    return ((double)(clock() - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_mergesort(int p, int r, int v[]) {
    clock_t inicio = clock();
    mergesort(p, r, v);
    return ((double)(clock() - inicio)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    int n = MAX;
    int *v = (int *)malloc(n * sizeof(int));
    double tempo;

    // Teste para Trocas Sucessivas
    gerar_vetor(n, v);
    tempo = medir_tempo(trocas_sucessivas, n, v);
    printf("Tempo Trocas Sucessivas: %f segundos\n", tempo);

    // Teste para Seleção
    gerar_vetor(n, v);
    tempo = medir_tempo(selecao, n, v);
    printf("Tempo Selecao: %f segundos\n", tempo);

    // Teste para Inserção
    gerar_vetor(n, v);
    tempo = medir_tempo(insercao, n, v);
    printf("Tempo Insercao: %f segundos\n", tempo);

    // Teste para Mergesort
    gerar_vetor(n, v);
    tempo = medir_tempo_mergesort(0,n, v);
    printf("Tempo Mergesort: %f segundos\n", tempo);



    free(v);
    return 0;
}
