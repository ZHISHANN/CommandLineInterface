#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>

#define Max_Value 20             //limit the size of count
#define MAX_BUFFER_SIZE 4096

char cmdBuffer; 

ListItem *LinkedListRemoveFromHead(LinkedList *list)
{
  int *NewList;

  if(list == NULL)
    return 1;
  else
  {
      NewList = list->head->next;
      list->head->next = NULL;          //assign first item->next to NULL
      list->head = NewList;             //change the head
      list->count--;                    //decrease count
  }
}

//find the last node
//put in data
//next -> NULL
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd)
{
  ListItem *NewList = malloc(sizeof(ListItem));

  ListItem *travel = list;

  if(list->head == NULL)
  {
      list->head = NewList;
      NewList->data = *(int*)(ItemToAdd->data); // Link the data part
      NewList->next = NULL;
      list->count++;
      list->tail = NewList;
  }
  else
  {
    // Traverse to the last node
    while(travel->next != NULL)
        travel = travel->next;

    NewList->data = *(int*)(ItemToAdd->data); // Link the data part
    NewList->next = NULL;
    list->count++;
    list->head->next = NewList;
    travel->next = NewList;   //link the address
    list->tail = NewList;
  }
  return NewList;
}

void ProcessKeyPress(char key)
{

}
