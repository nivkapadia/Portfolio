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

    // row zero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == 0)
            {
                printf("#");
            }
            else if (i + j <= n -1)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}