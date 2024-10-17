#include <stdio.h>

int main(void)
{
    int n = 5;
    int factorial = 1;

    for (int i = 1, st = n; i < 5; i++)
    {
        int temp = n * (n - i);
        factorial *= temp;
        n--;
    }
    printf("%i\n", factorial);
}