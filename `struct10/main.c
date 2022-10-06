#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list
{
    char *str;
    unsigned int len;
    struct list *next;
}structure;

structure *add_node_end(structure **head, const char *str)
{
    int len = 0, i = 0, len2 = 0;
    for(i; str[i] != '\0'; i++, len++);
    structure *newnode = malloc(sizeof(structure));
    if ((*head) == NULL)
    {
        newnode->str = strdup(str);
        if (!newnode->str)
        {
            free(newnode);
            return NULL;
        }
        newnode->len = len;
        newnode->next = *head;
        *head = newnode;
        return newnode;
    }

    newnode->str = strdup(str);
    if (!newnode->str)
    {
         free(newnode);
         return NULL;
    }
    newnode->len = len;
    newnode->next = (*head)->next;
    (*head)->next = newnode;

    structure **head2 = head;
    while ((*head2) != NULL)
    {
        len2++;
        (*head2) = (*head2)->next;
    }


}

    /*while ((*head) != NULL)
    {
        if ((*head)->next == NULL)
        {
            new_node->str = strdup(str);
            new_node->len = len;
            new_node->next = (*head)->next;
            (*head)->next = new_node;
        }
        (*head) = (*head)->next;
    }
    return new_node;*/

int main(void)
{
    structure *head = NULL;

    add_node_end(&head, "Anne");
    add_node_end(&head, "Colton");
    add_node_end(&head, "Daniel");

    while (head != NULL)
    {
        printf("[%d] -> %s\n", head->len, head->str);
        head = head->next;
    }

    return (0);
}
