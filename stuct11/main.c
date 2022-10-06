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
    int len = 0, i = 0;
    for(i; str[i] != '\0'; i++, len++);
    structure new_node = malloc(sizeof(structure));
}

int main(void)
{
    structure *head = NULL;

    add_node_end(&head, "Anne");
    add_node_end(&head, "Colton");

    return (0);
}
