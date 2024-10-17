#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &n);
    }
    while (n < 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i >= j; j++)
        {
            printf("%d", j + 1);
        }
        printf("\n");
    }
}