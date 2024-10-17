#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter a number: ");
    }
    while (n < 0 || n > 10);

    for (int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}