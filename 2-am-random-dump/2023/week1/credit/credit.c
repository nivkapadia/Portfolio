#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

long number(void);

int main(void)
{
    // number();
    long n = get_long("Enter a number: ");
    printf("%s", (string) n);
}

long number(void)
{
    return 0;
}