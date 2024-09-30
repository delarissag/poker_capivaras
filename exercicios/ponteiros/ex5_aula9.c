#include <stdio.h>
int main(void)
{
    int i, j, *p, *q;

    p = &i;
    q = p;
    *p = 1;

    printf("i=%d, *p=%d, *q=%d\n", i, *p, *q);

    q = &j;
    i = 6;
    *q = *p;

    printf("i=%d, j=%d, *p=%d, *q=%d\n", i, j, *p, *q);

    return 0;
}
