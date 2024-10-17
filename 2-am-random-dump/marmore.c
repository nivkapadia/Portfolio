#include <stdio.h>

int main(void)
{
    int n = 6;

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < (n * 2) + 3; j++)
        {
            if (j == n || j == n + 1 || j == n + 2)
                printf(" ");
            else if (j < n && j >= n - 1 - i)
                printf("#");
            else if (j < n && j < n - 1 - i)
                printf(" ");
            else
            {
                if (k <= i)
                {
                    printf("#");
                    k++;
                }
            }
        }
        printf("\n");
    }
}
