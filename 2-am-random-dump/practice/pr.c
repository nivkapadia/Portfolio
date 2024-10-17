#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // here because code is read top to bottom.
    do
    {
    n = get_int("Height: "); //asking user for the height of pyramid
    }
    while (n < 1 || n > 8);

    int i = 0;
    while (i < n)
    {
        printf("#\n");
        i++;
    }
}