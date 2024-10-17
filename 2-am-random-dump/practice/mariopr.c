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

    for (int r = 8; r < n; r++)
    {
        printf("#");
    }
    printf("\n");
    for (int q = 7; q < n; q++)
    {
        printf("#");
    }
    printf("\n");
    for (int p = 6; p < n; p++)
    {
        printf("#");
    }
    printf("\n");
    for (int o = 5; o < n; o++)
    {
        printf("#");
    }
    printf("\n");
    for (int m = 4; m < n; m++)
    {
        printf("#");
    }
    printf("\n");
    for (int l = 3; l < n; l++)
    {
        printf("#");
    }
    printf("\n");
    for (int k = 2; k < n; k++)
    {
        printf("#");
    }
    printf("\n");
    for (int j = 1; j < n; j++)
    {
        printf("#");
    }
    printf("\n");
    // last row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}