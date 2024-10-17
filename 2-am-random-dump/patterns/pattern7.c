#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &n);
    }
    while (n < 0 || n > 10);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        for (int k = 0; i <= i + k; k++)
        {
            printf(" ");
        }
        printf("\n");
    }
}