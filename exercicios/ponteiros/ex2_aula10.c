#include <stdio.h>
#define MAX 100
void dois_maiores(int n, int v[MAX], int *pr, int *seg){
    *pr = v[0];
    *seg = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] > *pr) {
            *seg = *pr;
            *pr = v[i];
        }
        else if(v[i] > *seg && v[i] != *pr){
            *seg = v[i];
        }
    }
    printf("\nprimeiro: %d\n", *pr);
    printf("segundo: %d\n", *seg);


}
int main(void){
    int n;
    int v[MAX];
    int pr,seg;


    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }

    dois_maiores(n,v,&pr,&seg);

    return 0;


}

