#include <stdio.h>

int main(void)
{
    int n = 5;
    for (int row = 0; row < n; row++);
    {
        // for every row print columns
        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }
        printf("\n");`
    }
}