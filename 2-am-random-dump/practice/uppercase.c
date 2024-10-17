#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uppercase(char *s);

int main(void)
{
    char *s = "Hello";
    uppercase(s);
}

void uppercase(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            printf("%c", s[i]);
        }
        else if (s[i] >= 'a' && s[i] < 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}