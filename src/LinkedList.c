#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>

#define Max_Value 20             //limit the size of count

/*LinkedList *CreateLinkedList()
{
  LinkedList *NewLinked = malloc(sizeof(LinkedList*));

  NewLinked->head = NULL;
  NewLinked->tail = NULL;
  //NewLinked->count = 0;

  return NewLinked;
}*/

ListItem *CreateListItem(void *data)
{
  ListItem *NewList = (ListItem*)malloc(sizeof(ListItem*));
  ListItem *temp_item;
  void *temp_data = data;

  if(NewList == NULL)
    printf("Error creating a new node.\n");

  NewList->data = temp_data;
  NewList->next = NULL;

  //NewList->prev = NULL;
  //temp_item = NewList;
  //temp_item->next = NewList;           //link previous node
  //temp_item = temp_item->next;

  return NewList;
}

//find the last node
//put in data
//next -> NULL
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd)
{
  //LinkedList *NewLinked = malloc(sizeof(LinkedList));
  //list = CreateLinkedList();

  ListItem *NewList = malloc(sizeof(ListItem));
  //NewList = CreateListItem(ItemToAdd);
  //list = NewList;

  //ListItem* NewList =  CreateListItem(ItemToAdd);
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

ListItem *LinkedListRemoveFromHead(LinkedList *list)
{
  ListItem *toDelete;

    if(list == NULL)
      return 1;
    else
    {
        toDelete = list;
        list = list->next;

        // Clears the memory occupied by first node
        //free(toDelete);
    }
  
}
