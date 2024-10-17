#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string input = get_string("Input:  ");
    printf("Output: ");
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        printf("%c", input[i]);
    }
    printf("\n");
}