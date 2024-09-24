#include <stdio.h>

#define MAX 100

void insercaoRecursiva(int v[], int n) {
    // Caso base: se n é 1, o vetor já está ordenado
    if (n <= 1) {
        return;
    }

    // Chama recursivamente para ordenar os primeiros n-1 elementos
    insercaoRecursiva(v, n - 1);

    // Insere o último elemento na posição correta
    int last = v[n - 1];
    int j = n - 2;

    // Move os elementos maiores que last para uma posição à frente
    while (j >= 0 && v[j] > last) {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = last;  // Coloca last na posição correta
}

int main() {
    int v[MAX], n;

    // Entrada de dados
    printf("Digite o numero de elementos (max %d): ", MAX);
    scanf("%d", &n);
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Ordena o vetor
    insercaoRecursiva(v, n);

    // Exibe o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
