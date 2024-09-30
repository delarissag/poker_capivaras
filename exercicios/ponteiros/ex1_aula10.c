#include <stdio.h>
#define MAX 100
void min_max(int n, int v[MAX], int *max, int *min){
    *max = v[0];
    *min = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] > *max) {
            *max = v[i];
        }
        if (v[i] < *min) {
            *min = v[i];
        }
    }
    printf("\nmin: %d\n", *min);
    printf("max: %d\n", *max);


}
int main(void){
    int n;
    int v[MAX];
    int max,min;


    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }

    min_max(n,v,&max,&min);

    return 0;


}

