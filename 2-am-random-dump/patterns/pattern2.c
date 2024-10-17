#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    do
    {
        printf("Enter a number: ");
        scanf("%i", &n);
    }
    while (n < 0 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%i", j);
        }
        printf("\n");
    }
}