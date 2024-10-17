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

    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            printf("%d ", n - j);
            j++;
        }
        printf("\n");
        i++;
    }
}