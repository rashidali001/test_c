#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
list_t *reference;

void free_list(list_t *head)
{
    reference = head;

}
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
        printf("%x\n", new_node);
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
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    list_t *head;

    head = NULL;
    add_node_end(&head, "Bob");
    add_node_end(&head, "&");
    add_node_end(&head, "Kris");
    add_node_end(&head, "love");
    add_node_end(&head, "asm");
    print_list(head);
    free_list(head);
    print_list(head);
    /*head = NULL;*/
    return (0);
}
