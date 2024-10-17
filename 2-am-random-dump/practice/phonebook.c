#include <cs50.h>
#include <stdio.h>
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
    people[0].number = "844";

    people[1].name = "Pinal";
    people[1].number = "845";

    string name = get_string("Enter Name: ");

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found\n");
            printf("Number: %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}