#include <stdio.h>
#include <cs50.h>

void print_grid(int n);
int get_size(void);

int main(void)
{
    int n = get_size();

    print_grid(n);
}

int get_size(void)
{

    int n;
    do
    {
        n = get_int("enter a number: ");
    }
    while (n < 0 || n > 8);
    return n;
}

void print_grid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i + j < n - 1; j++)
        {
            printf(".");
        }
        for(int k = 0; k <= n-1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}