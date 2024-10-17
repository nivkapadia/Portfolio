#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int vote;
}
candidate;

int main(void)
{
    candidate cands[];
    cand.name[] = {"Alice", "Bob"};
    cand.vote[] = {"2", "3"};

    for (int i = 0; i < 2; i++)
    {
        printf("%s %i\n" cands.name[i], cands.vote[i]);
    }
}