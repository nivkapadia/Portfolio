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

    // for row
    for (int i = 0; i < n; i++)
    {
        // for column
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
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