#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10 // Tamanho m�ximo do vetor

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
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

    selecao(n, v);

    printf("Vetor apos a ordenacao:\n");
    imprimir_vetor(n, v);

    free(v);
    return 0;
}
