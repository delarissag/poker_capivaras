#include <stdio.h>


#define MAX 10

int busca_binaria(int n, int v[MAX], int x)
{
    int esq, dir, meio;
    esq = -1;
    dir = n;
    while (esq < dir - 1) {
        meio = (esq + dir) / 2;
        if (v[meio] < x)
            esq = meio;
        else
            dir = meio;
    }
    return dir;
}

int main() {

    int n;
    int v[MAX];
    int x;

    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&v[i]);
    }

    printf("Informe o valor a buscar:\n");
    scanf("%d",&x);

    printf("Indice: %d\n",busca_binaria(n, v, x));

    return 0;
}

