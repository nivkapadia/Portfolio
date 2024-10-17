#include <stdio.h>
#include <cs50.h>

void meow(int n);

int main(void)
{
    meow(0);
}

void meow(int n)
{
    do
    {
        n = get_int("Enter number: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    printf("meow\n");
}