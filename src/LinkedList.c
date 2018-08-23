#include "LinkedList.h"
#include "CLI.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

ListItem *recalledItem = NULL;

/*Initialize for storing the data*/
ListItem *createListItem(void *data)
{
  ListItem *NewList = malloc(sizeof(ListItem*));

  NewList->data = (void *)(data);
  NewList->next = NULL;
  NewList->prev = NULL;

  return NewList;
}

/*
* 1. if head is NULL display error message
* 2. if head not NULL, free the previous head, assign it to NULL
* 3. update the head, change the head to the next of the head
* 4. always assign the next of the tail to the head of the list
* 5. update the count, everytime decrease by 1
*/
ListItem *linkedListRemoveFromHead(LinkedList *list)
{
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
    list->tail->next = list->head->next;
    list->head = list->head->next;
    list->head->prev = list->tail;
    list->count--;
  }

  if(list->count <= 0)
    list->count = 0;
}

/*
* 1. check the head, if is NULL
* 2. assign the ItemToAdd to add into head and tail of list
* 3. assign the ItemToAdd to head previous and tail
* 4. assign the ItemToAdd to tail previous and tail
* 5. update the count for the list
* 6. if head not NULL
* 7. insert the new data(ItemToAdd) to the next of the tail
* 8. assign next of new data to head of list
* 9. assign prev of new data to tail of list before update the tail of list
* 10. update the tail of list to new data;
* 11. assign the previous of head to tail of list
* 12. update the count of the list evrytime input, increase the count by 1
*/
ListItem *linkedListAddToTail(LinkedList *list, ListItem *ItemToAdd)
{
  if(list->head == NULL)
  {
    list->head = ItemToAdd;
    list->tail = ItemToAdd;
    list->head->next = list->tail;
    list->head->prev = list->tail;
    list->tail->next = list->head;
    list->tail->prev = list->head;
    list->count++;
  }
  else
  {
    list->tail->next = ItemToAdd;
    ItemToAdd->next = list->head;
    ItemToAdd->prev = list->tail;
    list->tail = ItemToAdd;
    list->head->prev = list->tail;
    list->count++;
  }
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
void linkedListInit(LinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
}
