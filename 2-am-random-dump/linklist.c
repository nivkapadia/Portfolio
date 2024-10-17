#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

bool find(node *head, int number);
void destroy(node *list);

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    node *x = list;
    while (x != NULL)
    {
        printf("%i\n", x->number);
        x = x->next;
    }

    if (find(list, 1) == true)
    {
        printf("Number found\n");
    }
    else
    {
        printf("Not found\n");
    }
    destroy(list);
}

bool find(node *head, int number)
{
    for (int i = 0; i < 3; i++)
    {
        if (head->number == number)
        {
            return true;
        }
        else
        {
            head = head->next;
        }
    }
    return 0;
}

void destroy(node *list)
{
    if (list->next == NULL)
    {
        free(list);
        list->next = NULL;
    }
    else
    {
        destroy(list->next);
    }
}