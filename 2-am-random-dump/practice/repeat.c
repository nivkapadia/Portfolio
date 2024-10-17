#include <stdio.h>
#include <cs50.h>

void hello(int n);

int main(void)
{
    hello(0);
}

void hello(int n)
{
    n = get_int("Enter a number: ");
    while (n > 0)
    {
        printf("hello, world\n");
        n--;
    }
}