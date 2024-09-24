#include <stdio.h>


#define MAX 10

int busca_ordenada(int n, int v[MAX], int x)
{
    int k;
    for (k = 0; k < n && v[k] < x; k++)
        ;
    return k;
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

    printf("Indice: %d\n",busca_ordenada(n, v, x));

    return 0;
}

