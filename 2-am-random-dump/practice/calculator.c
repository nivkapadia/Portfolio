#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    int z = x + y;
    // %i is a place holder. if you want to add any value of a variable to it, you must use place holder
    // for string place holder is %s, for float %f and so forth
    printf("%li\n", z);
}