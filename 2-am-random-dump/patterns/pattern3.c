#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Enter a number: ");
        scanf("%i", &n);
    }
    while (n < 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", j + 65);
        }
        printf("\n");
    }
}