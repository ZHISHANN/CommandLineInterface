#include "LinkedList.h"
#include "CLI.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

ListItem *recalledItem = NULL;

ListItem *CreateListItem(void *data)
{
  ListItem *NewList = malloc(sizeof(ListItem*));
  char *temp_data = data;

  NewList->data = temp_data;
  NewList->next = NULL;
  NewList->prev = NULL;

  return NewList;
}

ListItem *LinkedListRemoveFromHead(LinkedList *list)
{
  int *NewList;

  if(list->head == NULL)
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
      list->tail = NewList;
      NewList->data = (char *)ItemToAdd->data; // Link the data part
      NewList->next = NULL;
      list->count++;
  }
  else
  {
    // Traverse to the last node
    while(travel->next != NULL)
        travel = travel->next;

    list->tail = NewList;
    NewList->data = (char *)ItemToAdd->data; // Link the data part
    NewList->next = NewList;
    list->count++;
    list->head->next = NewList;
    travel->next = NewList;   //link the address
  }
  return NewList;
}

//get the index of the end of string
int indexOfString(Line *line)
{
  int buff = *(int *)line->buffer;
  int len = strlen(line->buffer);

  if (line != NULL)
  {
    line->index = len;
    line->last_index = len + 1;
  }
  else
    return line;

  return line;
}

char *recallPrevious(LinkedList *list)
{
  if(recalledItem == NULL)
    recalledItem = list->head;

  recalledItem = recalledItem->prev;

  return (char *)(recalledItem->data);
}

char *recallNext(LinkedList *list)
{
  if(recalledItem == NULL)
    recalledItem = list->tail;

  recalledItem = recalledItem->next;

  return (char *)(recalledItem->data);
}

void resetRecalledItem(LinkedList *list)
{
  recalledItem = list->head;
}
