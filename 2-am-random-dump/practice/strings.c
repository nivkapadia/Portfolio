#include <stdio.h>

int main(void)
{
    //There are two ways to use strings
    // This is the first method
    char greetings[] = "Hello";
    // this is the second method
    char *s = "YELLO";

    printf("%s\n", greetings);
    printf("%s\n", s);
}