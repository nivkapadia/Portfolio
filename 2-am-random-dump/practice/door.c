#include <stdio.h>

int main(void)
{
    int i;
    int doors[] = {4, 5, 3, 2, 6, 0, 1};

    for (i = 3; i < 7; i++)
    {
        if (doors[i] == 0)
        {
        printf("0 found behind %i th door\n", i);
        return 0;
        }
    }
    return 1;
}