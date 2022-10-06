#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list *node_pointer;

typedef struct list
{
    char *str;
    unsigned int len;
    node_pointer next;
}structure;

structure *add_node(structure **head, const char *str)
{
    int len = 0, i = 0;
    for(i; str[i] != '\0'; i++, len++);

    structure *newnode = malloc(sizeof(structure));
    if (newnode == NULL)
    {
        printf("Could not allocate memory!!\n");
        return (1);
    }
    newnode->str = strdup(str);
    if (!newnode->str)
    {
        free(newnode);
        return NULL;
    }
    newnode->len = len;
    newnode->next = *head;
    *head = newnode;

    return(newnode);
}

size_t printList(const structure *h)
{
    while (h != NULL)
    {
        printf("[%d] -> %s\n", h->len, h->str);
        h = h->next;
    }
}

int main()
{
    node_pointer head;

    add_node(&head, "Alexandro");
    add_node(&head, "Asaia");
    add_node(&head, "Augustin");
    add_node(&head, "Bennett");
    add_node(&head, "Bilal");
    add_node(&head, "Chandler");
    add_node(&head, "Damian");
    add_node(&head, "Daniel");
    add_node(&head, "Dora");
    add_node(&head, "Electra");
    add_node(&head, "Gloria");
    add_node(&head, "Joe");
    add_node(&head, "John");
    add_node(&head, "John");
    add_node(&head, "Josquin");
    add_node(&head, "Kris");
    add_node(&head, "Marine");
    add_node(&head, "Mason");
    add_node(&head, "Praylin");
    add_node(&head, "Rick");
    add_node(&head, "Rick");
    add_node(&head, "Rona");
    add_node(&head, "Siphan");
    add_node(&head, "Sravanthi");
    add_node(&head, "Steven");
    add_node(&head, "Tasneem");
    add_node(&head, "William");
    add_node(&head, "Zee");

    printList(head);

    return (0);
}
