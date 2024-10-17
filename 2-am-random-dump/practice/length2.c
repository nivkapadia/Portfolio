#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    string name = get_string("Name: ");
    char c = name[i];
    int length = strlen(name);
    printf("%i\n", length);
    printf("%i\n", c);
}