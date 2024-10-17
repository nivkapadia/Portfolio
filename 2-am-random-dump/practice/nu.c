#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *n[101];
    printf("Enter a number: ");
    scanf("%s", n);
    printf("Digits: ", atoi(n));
}