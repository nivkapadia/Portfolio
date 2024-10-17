#include <stdio.h>
#include <cs50.h>

int get_length(string name);

int main(void)
{
    string name = get_string("Name: ");
    int length = get_length(name);
    printf("%i\n", length);
}

int get_length(string name)
{
    int i = 0;
    while (name[i] != '\0')
    {
        i++;
    }
    return i;
}