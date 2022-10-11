#include <stdio.h>
#include <stdlib.h>

typedef struct node *node_ptr;

typedef struct node
{
    node_ptr prev;
    int data;
    node_ptr next;
}node;

node_ptr create_node(int data)
{
    node_ptr node_item = malloc(sizeof(node));
    node_item->prev = NULL;
    node_item->data = data;
    node_item->next = NULL;
    return node_item;
}

node_ptr getnode(node_ptr head, int data)
{
    node_ptr node_item;
    node_item = create_node(data);
    if (head == NULL)
    {
        head = node_item;
        return;
    }

    /* At the beginning*/
    /*node_item->next = head;
    head->prev  = node_item;
    head = node_item;
    return head;*/

    /* At the end*/
    node_ptr tp = head;
    while (tp->next != NULL)
        tp = tp->next;

    tp->next = node_item;
    node_item->prev = tp;
    return head;
}

node_ptr atpoint(node_ptr head, int data, int position)
{
    node_ptr node_item;
    node_item = create_node(data);
    node_ptr tp = head;
    int i = 1;

    if (position == 1)
    {
        node_item->next = head;
        head->prev = node_item;
        head = node_item;
        return head;
    }

    while (i < position - 1)
    {
        tp = tp->next;
        i++;
    }
    node_item->next = tp->next;
    tp->next->prev = node_item;
    tp->next = node_item;
    node_item->prev = tp;
    return head;

}
node_ptr delete_node(node_ptr head, int position)
{
    node_ptr tp = head;
    int i = 0;
    if (position == 1)
    {
        head->next->prev = head->prev;
        head = head->next;
        return head;
    }
    while (i < position - 1)
    {
        tp = tp->next;
        i++;
    }
    tp->prev->next = tp->next;
    tp->next->prev = tp->prev;
    free(tp);
    return head;
}

int main()
{
    node_ptr head = NULL;
    head = getnode(head, 45);
    head = getnode(head, 55);
    head = getnode(head, 65);
    head = getnode(head, 75);
    head = getnode(head, 85);
    head = getnode(head, 95);
    head = getnode(head, 105);
    head = getnode(head, 115);
    head = atpoint(head, 66, 3);

    /*head = delete_node(head  , 4);*/

    node_ptr loop = head;
    while (loop != NULL)
    {
        printf("[%d]\n", loop->data);
        loop = loop->next;
    }

}
