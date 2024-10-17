#include <stdio.h>
#include <cs50.h>

int get_number(void);
void pattern1(int size);
void pattern2(int size);

int main(void)
{
    int n = get_number();
    // pattern1(n);
    pattern2(n);
}

int get_number(void)
{
    int n;
    do
    {
       n = get_int("Enter a number: ");
    }
    while (n <= 0 || n > 8);
    return n;
}

void pattern1(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return;
}

void pattern2(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - 1; j++)
        {
            printf(".");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

// void pattern2(int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             if (i + j < size - 1)
//             {
//                 printf(" ");
//             }
//             else
//             {
//                 printf("#");
//             }
//          }
//         printf("\n");
//     }
}