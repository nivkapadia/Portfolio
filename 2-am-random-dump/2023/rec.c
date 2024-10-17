#include <stdio.h>

void draw(int n);

int main(void)
{
    draw(4);
}

void draw(int n)
{
    if (n <= 0)
    {
        return;
    }
    for (int i = n - 1; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

    draw(n - 1);
}