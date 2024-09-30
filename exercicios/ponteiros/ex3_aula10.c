#include <stdio.h>
#define MAX 100

void soma_prod(int a, int b, int *soma, int *prod){
    *soma = a + b;
    *prod = a * b;
}
int main(void){
    int n;
    int v[MAX];
    int soma=0, prod=1;
    int maior_q_soma=0;
    int maior_q_prod=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);

        soma_prod(soma,v[i],&soma,&prod);

    }

    for(int i=0;i<n;i++){
        if (v[i] > soma) {
            maior_q_soma++;
        }
        if (v[i] > prod) {
            maior_q_prod++;
        }

    }

    printf("Soma: %d\n", soma);
    printf("Produto: %d\n", prod);
    printf("Numeros maiores que a soma: %d\n", maior_q_soma);
    printf("Numeros maiores que o produto: %d\n", maior_q_prod);

    return 0;


}

