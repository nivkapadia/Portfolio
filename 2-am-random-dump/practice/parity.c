#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("n: ");

    //if n is even
    if (n%2 == 0)
    {
        printf("n is even\n");
    }
    //else
    else
    {
        printf("n is odd\n");
    }
}