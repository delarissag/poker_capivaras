#include <stdio.h>
int main(void)
{
    int i, *p, *q;
    p = &i;
    q = &i;

    i = 1;

    printf("i=%d, p=%d, q=%d \n", i, p, q);
    printf("*p=%d, *q=%d \n",*p, *q);
    printf("&i=%d, &p=%d, &q=%d \n", &i, &p, &q);
    printf("*&i=%d, *&p=%d, *&q=%d \n", *&i, *&p, *&q);

    return 0;
}

