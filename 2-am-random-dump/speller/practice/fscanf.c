#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char *name;
    struct node *next;
} node;

int main(void)
{
    FILE *file;
    file = fopen("fruits.txt", "r");
    if (file == NULL)
    {
        return 1;
    }

    char buffer[12];

    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return 1;
        }

        strcpy(newNode->name, buffer);
    }
}
