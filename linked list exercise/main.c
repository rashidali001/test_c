#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node *nodeptr;

nodeptr head = NULL; // (main)Pointer to the list


typedef struct node
{
    int key;
    int data;
    nodeptr next;
}node;

void insertFirst(int key, int data)
{
    nodeptr created = malloc(sizeof(node));
    created->key = key;
    created->data = data;
    created->next= head;
    head = created;
}
void printList()
{
    nodeptr print = head;
    while (print != NULL)
    {
        printf("[KEY: %d, DATA: %d]\n", print->key, print->data);
        print = print->next;
    }
}

_Bool isEmpty()
{
    return head == NULL;
}

nodeptr deleteFirst()
{
    nodeptr deleted = malloc(sizeof(node));
    deleted->data = head->data;
    deleted->key = head->key;
    deleted->next = NULL;
    head = head->next;
    return deleted;
}
nodeptr find(int key)
{
    nodeptr found = malloc(sizeof(node));

    nodeptr iterates = head;
    while(iterates != NULL)
    {
        if(iterates->key == key)
        {
            found->key = iterates->key;
            found->data = iterates->data;
            found->next = NULL;
            return found;
        }
        iterates = iterates->next;
    }
    return NULL;

}

void delete(int key)
{
    nodeptr loop = head;
    nodeptr lastReference = loop;
    while(loop != NULL)
    {

        if (loop->key == key)
        {
            lastReference->next = loop->next;
            loop->next = NULL;
        }
        lastReference = loop;
        loop = loop->next;
    }

}

void sort()
{
    nodeptr current = head;
    int tempData, tempKey;
    nodeptr front = current->next;
    while(current != NULL)
    {
        if(current->data  > front->data)
        {
            tempData = current->data;
            current->data = front->data;
            front->data = tempData;

            tempKey = current->key;
            current->key = front->key;
            front->key = tempKey;

        }
        current = current->next;
        front = front->next;
    }

}
int main()
{
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);

   printf("Original List: \n");

   //print list
   printList();

   while(!isEmpty()) {
      nodeptr temp = deleteFirst();
      printf("\nDeleted value:");
      printf("[KEY: %d, DATA: %d]\n", temp->key, temp->data);
   }

   printf("\nList after deleting all items: ");
   if(isEmpty())
   {
       printf("LIST DOESN'T EXIST!! (STATUS: deleted)\n");
   }
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);

   printf("\nRestored List: \n");
   printList();
   printf("\n");

   nodeptr foundLink = find(4);

   if(foundLink != NULL) {
      printf("current found: ");
      printf("[KEY: %d, DATA: %d]\n", foundLink->key, foundLink->data);
      printf("\n");
   } else {
      printf("current not found.");
   }

   delete(4);
   printf("List after deleting an item: \n");
   printList();
   printf("\n");

    foundLink = find(4);

   if(foundLink != NULL) {
      printf("current found: ");
      printf("[KEY: %d, DATA: %d]\n", foundLink->key, foundLink->data);
      printf("\n");
   } else {
      printf("current not found.");
   }

    printf("\n");
    sort();
   printf("List after sorting the data: \n");
   printList();




}
