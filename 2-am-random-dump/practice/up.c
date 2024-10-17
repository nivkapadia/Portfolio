#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    for (int i = 0; i < strlen(name); i++)
    {
        printf("%c", toupper(name[i]));
    }
    printf("\n");
}