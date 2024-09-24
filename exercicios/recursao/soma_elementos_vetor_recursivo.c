#include <stdio.h>
#define MAX 10
float soma(int n, float v[MAX]){
    if(n==1){
        return v[0];
    }
    else{
        return v[n-1]+soma(n-1,v);
    }
}

int main() {
    int n;
    float v[MAX];

    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &v[i]);
    }

    printf("%.2f",soma(n,v));
    return 0;
}
