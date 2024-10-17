#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long n = get_long("number: ");
    int c = 0;
    do
    {
        n = n / 10;
        c++;
    }
    while (n != 0);

    printf("%i\n", c);
}