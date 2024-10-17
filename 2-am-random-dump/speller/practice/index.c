#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
     char s = argv[1][0];
     printf("%i\n", tolower(s) - 'a');
}
