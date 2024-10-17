#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    char name[20];
    struct node *next;
} node;

node *hashTable[3];

unsigned int hash(char *name);
bool load(char *name);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Use 4 Command line arguments\n");
        return 1;
    }

    load(argv[1]);
    load(argv[2]);
    load(argv[3]);

    printf("%i\n", hash(argv[1]));
}

unsigned int hash(char *name)
{
    int x = 0;

    for (int i = 0; i < strlen(name); i++)
    {
        x += (name[i] -'a') * i;
    }
    return x;
}

bool load(char *name)
{
    int index = hash(name);
    node *newNode = malloc(sizeof(node));

        strncpy(newNode->name, name, sizeof(newNode->name));
        newNode->next = NULL;

        hashTable[index] = newNode;

        return true;
}
