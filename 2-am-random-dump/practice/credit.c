#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_digits(char *number);

int main(void)
{
    char number[20];
    printf("Enter a number: ");
    scanf("%s", number);
    
    long CC = atoi(number); // converting string to number

    int digits = count_digits(number);
    printf("%d\n", digits);
}

// void count_digits(long number)
// {
//     int count_digits = 0;
//     while (number > 0)
//     {
//         number = number/10;
//         count_digits++;
//     }
//     printf("%d\n", count_digits);
// }

// void count_digits(long number)
// {
//     int i;
//     for (i = 0; number != 0; i++)
//     {
//         number /= 10;
//     }
//     printf("%d\n", i);
// }

int count_digits(char number[])
{
    return strlen(number);
}