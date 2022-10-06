#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr; //Pointer to a struct

struct node
{
  int data;
  Nodeptr next;
};

typedef struct node node;

int main()
{
    Nodeptr Head = NULL; // This is a pointer to a struct
    Head = malloc(sizeof(node));
    // Creating the 1st List
    Head->data = 1000;
    Head->next = NULL;

    Nodeptr temp; // This is a pointer to a struct
    // Creating the 2nd List
    temp = malloc(sizeof(node));
    temp->next = Head;
    temp->data = 2000;
    Head = temp;
    // Creating the 3rd List
    temp = malloc(sizeof(node));
    temp->next = Head;
    temp->data = 3000;
    Head = temp;


    while (Head != NULL)
    {
        printf("%d\n", Head->data);
        Head = Head->next;
    }


    return (0);
}
