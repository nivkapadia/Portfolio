#include<stdio.h>
#include <string.h>

int main()
{
    char n[101];
    printf("Enter no\n");
    scanf("%100s",n);
    printf("No of digits=>%lu\n",strlen(n));
}