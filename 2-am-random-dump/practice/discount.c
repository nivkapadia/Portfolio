#include <stdio.h>
#include <cs50.h>

int discount(int n);

int main(void)
{
    int regularprice = get_int("regular price: ");
    printf("%i\n", discount(regularprice));
}

int discount(int n)
{
    return n * .85;
}