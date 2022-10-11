#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef struct node *node_ptr;
typedef struct node
{
    node_ptr prev;
    int data;
    node_ptr next;
}node;

int data;

node_ptr creatNode(int data)
{
    node_ptr newNode = malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(node_ptr head)
{
    printf("\n***Traversing***\n");
    if (head == NULL)
    {
        printf("No items to display!! List is empty...\n");
        return;
    }
    int positon = 1;
    node_ptr tp = head;
    while(tp != NULL)
    {
        printf("Position [%d] - [%d]\n",positon, tp->data);
        tp = tp->next;
        positon++;
    }
    return;
}
node_ptr insertAtFirst(node_ptr head)
{
    printf("\n***Insertion at beginning***\n");
    printf("Enter your integer data only!!\n");
    printf(": ");
    scanf("%d", &data);
    node_ptr newNode = creatNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}
node_ptr insertAtPoint(node_ptr head)
{
    printf("\n***Insertion at a point***\n");
    if (head == NULL)
    {
        printf("List is empty. Data will be inserted at the beginning!\n");
        head = insertAtFirst(head);
        return head;

    }
    int position;
    int list_no = 0;/*Getting the no of elements in a list*/

    while (1)
    {
        printf("What position would you like to insert at: ");
        scanf("%d", &position);
        node_ptr move = head;
         while(move != NULL)
        {
            list_no++;
            move = move->next;
        }

        if (position > list_no)
        {
            printf("Not Possible!\n");
        }
        else
            break;

    }
    printf("Enter your integer data: ");
    scanf("%d", &data);

    node_ptr newNode = creatNode(data);
    node_ptr tp = head;


    int i = 1;
    if (position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    while (i < position - 1)
    {
        tp = tp->next;
        i++;
    }
    if (tp->next == NULL)
    {
        tp->next = newNode;
        newNode->prev = tp;
        return head;
    }
    newNode->next = tp->next;
    tp->next->prev = newNode;
    tp->next = newNode;
    newNode->prev = tp;
    return head;
}

node_ptr deleteAtFirst(node_ptr head)
{
    printf("\n***Deletion at a beginning***\n");
    if (head == NULL)
    {
        printf("Error!! No item to delete.\n");
        return head;
    }

    if (head->next == NULL)
    {
        head = NULL;
        return head;
    }
    head->next->prev = NULL;
    head = head->next;
    return head;
}
node_ptr deleteAtPoint(node_ptr head)
{
    printf("\n***Deletion at a point***\n");
    if (head == NULL)
    {
        printf("Error!! No item to delete.\n");
        return head;
    }
    int position;
    int list_no = 0;
    node_ptr move = head;
    while (move != NULL)
    {
        list_no++;
        move = move->next;
    }
    while (1)
    {
        printf("Enter position: ");
        scanf("%d", &position);

        if (position > list_no)
        {
            printf("Not possible!\n");
        }
        else
            break;
    }
    if (position == 1)
    {
        if (head->next == NULL)
        {
            head = NULL;
            return head;
        }
        head->next->prev = NULL;
        head = head->next;
        return head;
    }

    node_ptr tp = head;
    int i = 0;

    while (i < position - 1)
    {
        tp = tp->next;
        i++;
    }

    if (tp->next == NULL)
    {
        tp->prev->next = NULL;
        free(tp);
        return head;
    }
    tp->prev->next = tp->next;
    tp->next->prev = tp->prev;
    free(tp);
    return head;
}

void getdata(node_ptr head)
{
    printf("\n***Get data at a point***\n");
    if (head == NULL)
    {
        printf("Error!! List is empty.\n");
        return;
    }
    int position;
    int i = 0;
    node_ptr tp = head;
    printf("Enter position to retrieve data: ");
    scanf("%d", &position);
    if (position == 1)
    {
        printf("Data at position [%d] is [%d]\n", position, head->data);
        return;
    }

    while (i < position - 1)
    {
        tp = tp->next;
        i++;
    }
    printf("Data at position [%d] is [%d]\n", position, tp->data);
    return;

}

int main()
{
    node_ptr head = NULL;
    int choice;
    printf("\t******WELCOME TO THE DOUBLY LINKED LIST PROGRAM******\n");
    printf("\nOperations\n\n");
    printf("Traversing - (1)\nInserting at beginning - (2)\nInserting at a point - (3)\nDeletion at beginning - (4)\nDeletion at a point - (5)\nGet data at a point - (6)\nExit - (0)\n");

    while (1)
    {
        printf("\nEnter an operation: \n");
        scanf("%d", &choice);

        if (!(choice >= 1 && choice <= 6))
        {
            if (choice == 0)
                break;
            printf("Invalid option!\n");
            break;
        }

        switch(choice)
        {
            case 1:
                traverse(head);
                break;
            case 2:
                head = insertAtFirst(head);
                break;
            case 3:
                head = insertAtPoint(head);
                break;
            case 4:
                head = deleteAtFirst(head);
                break;
            case 5:
                head = deleteAtPoint(head);
                break;
            case 6:
                getdata(head);
                break;
            default :
                printf("Invalid input!!\n");
                break;
        }
    }
    printf("\nExiting program.....\n");
    printf("Exited\n");
}
