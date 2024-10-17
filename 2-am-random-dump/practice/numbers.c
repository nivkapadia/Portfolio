#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Niv";
    people[0].number = "+91-73833-90998";

    people[1].name = "Pinal";
    people[1].number = "+91-82005-53480";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "Niv") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found");
    return 1;
}