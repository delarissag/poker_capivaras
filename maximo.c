
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (5)


int maximo(int n, int v[MAX])
{
int i, x;
x = v[0];
for (i = 1; i < n; i++)
if (x < v[i])
x = v[i];
return x;
}

int main() {
    int n;
    int v[n];
    scanf()
}
