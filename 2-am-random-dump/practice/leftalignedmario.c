#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // here because code is read top to bottom.
    do
    {
        n = get_int("Height: "); //asking user for the height of pyramid
    }
    while (n < 1 || n > 8); //repeats "do" if true, continues further if false

    int j;
    // for row
    for (int i = 0; i < n; i++)
    {
        // for space
        for (int k = 0; k < j - i - 1; k++)
        {
            printf(" ");
        }
        // for column
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}