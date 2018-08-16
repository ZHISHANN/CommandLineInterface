#include "LinkedList.h"
#include "CLI.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

ListItem *recalledItem = NULL;

/*Initialize for storing the data*/
ListItem *CreateListItem(void *data)
{
  ListItem *NewList = malloc(sizeof(ListItem*));

  NewList->data = (void *)(data);
  NewList->next = NULL;
  NewList->prev = NULL;

  return NewList;
}

/*
* 1. if head is NULL display error message
* 2. create a newList
* 3. free the previous head, assign it to NULL
* 4. update the head, change the head to the next of the head
* 5. always assign the next of the tail to the head of the list
* 6. update the count, everytime decrease by 1
*/
ListItem *LinkedListRemoveFromHead(LinkedList *list)
{
  LinkedList *NewList;

  if(list->head == NULL)
    printf("Deletion is not possible..");
  else if(list->count == 1)
  {
    list->tail = NULL;
    list->head = NULL;
    list->count--;
  }
  else
  {
    list->head->prev = NULL;
    NewList = list->head->next;
    list->head->next = NULL;          //assign first item->next to NULL
    list->head = NewList;             //change the head
    list->tail->next = list->head;
    list->head->prev = list->tail;
    list->count--;                     //decrease count
  }

  if(list->count <= 0)
    list->count = 0;
}

/*
* 1. check the head, if is NULL
* 2. assign the newList to add into list
* 3. update the head tail and count for the list
* 4. if head not NULL
* 5. find the last node to insert the input data
* 6. update the tail and count of the list evrytime input
*/
ListItem *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd)
{
  //ListItem *NewList = ItemToAdd;

  if(list->head == NULL)
  {
    list->head = ItemToAdd;
    list->tail = ItemToAdd;
    ItemToAdd->next = list->head;
    ItemToAdd->prev = list->tail;
    list->count++;
  }
  else
  {
    list->tail->next = ItemToAdd;
    ItemToAdd->prev = list->tail;
    list->tail = ItemToAdd;
    ItemToAdd->next = list->head;
    list->head->prev = list->tail;
    list->count++;
  }
  return ItemToAdd;
}

/*
* 1. assign the recalledItem as head at fisrt if the given recalledItem was NULL
* 2. assign the recalledItem to the next previous recalledItem
*/
char *recallPrevious(LinkedList *list)
{
  if(recalledItem == NULL)
    recalledItem = list->head;

  recalledItem = recalledItem->prev;

  return (char *)(recalledItem->data);
}

/*
* 1. assign the recalledItem as tail at fisrt if the given recalledItem was NULL
* 2. assign the recalledItem to the next recalledItem
*/
char *recallNext(LinkedList *list)
{
  if(recalledItem == NULL)
    recalledItem = list->tail;

  recalledItem = recalledItem->next;

  return (char *)(recalledItem->data);
}

/*set the recalledItem back to head of the list to start over*/
void resetRecalledItem(LinkedList *list)
{
  recalledItem = list->head;
}

/*Initialize the linked list*/
void LinkedListInit(LinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
}
