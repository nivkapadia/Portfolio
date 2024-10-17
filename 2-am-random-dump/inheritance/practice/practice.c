#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
int x = 1;
person *lastChild;

person *createFamily(int generations);

int main(void)
{
    createFamily(GENERATIONS);
}

person *createFamily(int generations)
{
    if (x == 1)
    {
        lastChild = malloc(sizeof(person));
        if (lastChild == NULL)
        {
            return false;
        }
        x--;
    }

    if (generations > 1)
    {
        lastChild->parents[0] = createFamily(generations - 1);
        lastChild->parents[1] = createFamily(generations - 1);
    }
    return NULL;
}