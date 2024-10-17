#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int MINE = 2;
    int points = get_int("How many points did you lose?");
    if (points > MINE)
    {
        printf("You lost more points than me");
    }
    else if (points < MINE)
    {
        printf("You lost less points than me");
    }
    else
    {
        printf("you lost exactly the same number of points as me");
    }
}