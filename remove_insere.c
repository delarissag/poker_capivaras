#include <stdio.h>

#define MAX 100

int remove_elemento(int n, int v[MAX], int k) {
    for (int i = k; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    return n - 1;
}

int remove_R(int n, int v[MAX], int k) {
    if (k >= n) return n;
    if (k < n - 1) {
        v[k] = v[k + 1];
        return remove_R(n - 1, v, k);
    }
    return n - 1;

int insere(int n, int v[MAX], int k, int y) {
    for (int i = n; i > k; i--) {
        v[i] = v[i - 1];
    }
    v[k] = y;
    return n + 1;
}

int insere_R(int n, int v[MAX], int k, int y) {
    if (n == k) {
        v[n] = y;
        return n + 1;
    }
    v[n] = v[n - 1];
    return insere_R(n - 1, v, k, y);
}

int main() {
    int v[MAX], n = 0;

    printf("Insira o numero de elementos no vetor (max %d): ", MAX);
    scanf("%d", &n);
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int k;
    printf("Digite o indice do elemento a ser removido (nao-recursiva): ");
    scanf("%d", &k);
    if (k >= 0 && k < n) {
        n = remove_elemento(n, v, k);
        printf("Elemento removido. Novo vetor:\n");
    } else {
        printf("Indice invalido!\n");
    }

    // Exibir o vetor atualizado
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Digite o indice do elemento a ser removido (recursiva): ");
    scanf("%d", &k);
    if (k >= 0 && k < n) {
        n = remove_R(n, v, k);
        printf("Elemento removido. Novo vetor:\n");
    } else {
        printf("Indice invalido!\n");
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    int y;
    printf("Digite o indice para inserir o novo elemento (nao-recursiva): ");
    scanf("%d", &k);
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &y);
    if (k >= 0 && k <= n) {
        n = insere(n, v, k, y);
        printf("Elemento inserido. Novo vetor:\n");
    } else {
        printf("Indice invalido!\n");
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Digite o indice para inserir o novo elemento (recursiva): ");
    scanf("%d", &k);
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &y);
    if (k >= 0 && k <= n) {
        n = insere_R(n, v, k, y);
        printf("Elemento inserido. Novo vetor:\n");
    } else {
        printf("Indice invalido!\n");
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
