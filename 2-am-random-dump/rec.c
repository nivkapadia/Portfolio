#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    draw(4);
}

void draw(int n)
{
    if (n < 1)
    {
        return;
    }

    draw(n - 1);

    for (int i = 5; i > n; i--)
    {
        printf("#");
    }
    printf("\n");
}
