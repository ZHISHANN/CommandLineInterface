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

  NewList->data = (void *)(data);
  NewList->next = NULL;
  NewList->prev = NULL;

  return NewList;
}

ListItem *LinkedListRemoveFromHead(LinkedList *list)
{
  LinkedList *NewList;

  if(list->head == NULL)
    printf("Deletion is not possible..");
  else
  {
    NewList = list->head->next;
    list->head->next = NULL;          //assign first item->next to NULL
    list->head = NewList;             //change the head
    list->tail->next = list->head;
    list->count--;                   //decrease count
  }
}

//find the last node
//put in data
//next -> NULL
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd)
{
  ListItem *NewList = malloc(sizeof(ListItem));
  ListItem *temp_list = malloc(sizeof(ListItem));
  ListItem *temp = malloc(sizeof(ListItem));

  if(list->count == 1)
    list->head->next = NewList;

  if(list->head == NULL)
  {
      list->head = NewList;
      list->tail = NewList;
      NewList->data = ItemToAdd->data; // Link the data part
      NewList->next = NewList;
      //NewList = NewList->next;
      NewList->prev = list->tail;
      list->count++;
  }
  else
  {
     if(list->tail->next == NULL)
      list->tail->next = NewList;

     NewList->prev = list->tail;
     list->tail = NewList;
     NewList->data = ItemToAdd->data; // Link the data part
     NewList->next = list->head;
     list->count++;
  }
  return NewList;
}

//get the index of the end of string
/*int indexOfString(line *Line)
{
  int len = strlen(Line->buffer);

  if (Line != NULL)
  {
    Line->index = len;
    Line->last_index = len + 1;
  }
  else
    return Line;

  return Line;
}*/

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

void LinkedListInit(LinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
}
