#include <stdio.h>
#include <stdlib.h>

typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

list_t *reference;

void print_list(const list_t *h)
{
    while (h != NULL)
    {
        printf("[%d] -> %s\n", h->len, h->str);
        h = h->next;
    }
}
list_t add_node_end(list_t **head, const char *str)
{
    int length = 0, i = 0;
    for(i; str[i] != '\0'; i++, length++)
        ;
    list_t *new_node = malloc(sizeof(list_t));
    if ((*head) == NULL)
    {
        new_node->len = length;
        new_node->str = str;
        new_node->next = (*head);
        (*head) = new_node;
    }
    else
    {
        new_node->len = length;
        new_node->str = str;
        new_node->next = (NULL);
        reference->next = new_node;
    }
    reference = new_node;
}

int main(void)
{
    list_t *head;
    head = NULL;

    add_node_end(&head, "Anne");
    add_node_end(&head, "Colton");
    add_node_end(&head, "Corbin");
    add_node_end(&head, "Daniel");
    add_node_end(&head, "Danton");
    add_node_end(&head, "David");
    add_node_end(&head, "Gary");
    add_node_end(&head, "Holden");
    add_node_end(&head, "Ian");
    add_node_end(&head, "Ian");
    add_node_end(&head, "Jay");
    add_node_end(&head, "Jennie");
    add_node_end(&head, "Jimmy");
    add_node_end(&head, "Justin");
    add_node_end(&head, "Kalson");
    add_node_end(&head, "Kina");
    add_node_end(&head, "Matthew");
    add_node_end(&head, "Max");
    add_node_end(&head, "Michael");
    add_node_end(&head, "Ntuj");
    add_node_end(&head, "Philip");
    add_node_end(&head, "Richard");
    add_node_end(&head, "Samantha");
    add_node_end(&head, "Stuart");
    add_node_end(&head, "Swati");
    add_node_end(&head, "Timothy");
    add_node_end(&head, "Victor");
    add_node_end(&head, "Walton");
    print_list(head);
    printf("reference - %x : %s\n\n\n",reference, reference->str);

    return (0);
}
