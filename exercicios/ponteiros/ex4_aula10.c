#include <stdio.h>
#define MAX 100

int *maximo(int n, int v[MAX]){
    int *max = &v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] > *max) {
            max = &v[i];
        }
    }

    return max;
}

int main(){
    int n;
    int v[MAX];


    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }

    printf("\nMaior elemento: %d\n", *maximo(n,v));

    return 0;


}

