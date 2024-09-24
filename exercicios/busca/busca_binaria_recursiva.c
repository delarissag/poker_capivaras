#include <stdio.h>


#define MAX 10

int busca_binaria_R(int esq, int dir, int v[MAX], int x)
{
    int meio;
    if (esq == dir - 1)
        return dir;
    else {
        meio = (esq + dir) / 2;
        if (v[meio] < x)
            return busca_binaria_R(meio, dir, v, x);
        else
            return busca_binaria_R(esq, meio, v, x);
    }
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

    printf("Indice: %d\n",busca_binaria_R(0,n, v, x));

    return 0;
}

