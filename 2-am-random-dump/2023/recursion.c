#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main(void)
{
    int n = get_int("Enter a number: ");

    draw(n);
}

void draw(int n)
{
    if (n <= 0)
    {
        return;
    }



    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

    draw(n - 1);
}