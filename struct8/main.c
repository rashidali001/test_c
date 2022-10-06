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

node_pointer head = NULL;

void add_node(char* str)
{
    int len = 0, i = 0;
    for(i; str[i] != '\0'; i++, len++);

    node_pointer _new = malloc(sizeof(structure));
    _new->str = str;
    _new->len = len;
    _new->next = head;
    head = _new;
}
void printList()
{
    node_pointer print = head;

    while(print != NULL)
    {
        printf("[%d] -> %s\n", print->len, print->str);
        print = print->next;
    }
}
int main()
{
    add_node("Alexandro");
    add_node("Asaia");
    add_node("Augustin");
    add_node("Bennett");
    add_node("Bilal");
    add_node("Chandler");
    add_node("Damian");
    add_node("Daniel");
    add_node("Dora");
    add_node("Electra");
    add_node("Gloria");
    add_node("Joe");
    add_node("John");
    add_node("John");
    add_node("Josquin");
    add_node("Kris");
    add_node("Marine");
    add_node("Mason");
    add_node("Praylin");
    add_node("Rick");
    add_node("Rick");
    add_node("Rona");
    add_node("Siphan");
    add_node("Sravanthi");
    add_node("Steven");
    add_node("Tasneem");
    add_node("William");
    add_node("Zee");

    printList();
    return (0);


}
