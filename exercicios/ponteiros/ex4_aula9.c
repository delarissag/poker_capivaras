#include <stdio.h>
int main(void)
{
    int a, b, c, *ptr;

    a = 3;
    b = 7;
    printf("a=%d, b=%d\n", a, b);

    ptr = &a;
    c = *ptr;

    ptr = &b;
    a = *ptr;

    ptr = &c;
    b = *ptr;

    printf("a=%d, b=%d\n", a, b);

    return 0;
}
