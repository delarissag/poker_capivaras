#include <stdio.h>
int main(void)
{
    int i, *p;
    p = &i;

    i = 1;

    printf("i=%d\n\n", i);
    printf("*p=%d\n\n",*p);
    printf("&p=%d\n\n",&p);
    printf("*&p=%d\n\n",*&p);
    printf("&*p=%d\n\n",&*p);
    printf("&i=%d\n\n",&i);
    printf("*&i=%d\n\n",*&i);
    printf("*i e &*i sao invalidos.\n\n");

    return 0;
}

