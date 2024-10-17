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

    // for rows
    for (int i = 0; i < n; i++)
    {
        // for columns
        for (int j = 0; j < 2 + (n * 2); j++)
        {
            if (j == n || j == n + 1 || i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}