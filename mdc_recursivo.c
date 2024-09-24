#include <stdio.h>

int mdc(int x,int y){
    if(y==0){
        return x;
    }
    else{
        return mdc(y, x % y);
    }
}

int main() {
    int x,y;
    scanf("%d %d",&x,&y);

    int maximo_divisor_comum = mdc(x,y);
    printf("%d",maximo_divisor_comum);
    return 0;
}
