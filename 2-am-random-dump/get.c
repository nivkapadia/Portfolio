#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    printf("Enter a number: ");
    scanf("%s", s);

    printf("%s\n", s);
}