#include <stdio.h>

void fact(int n);

int main(void)
{
    fact(6);
}

void fact(int n)
{
    int x = n;
    while (x - 1 >= 1)
    {
        n *= x - 1;
        x--;
    }
    printf("%i\n", n);
}
