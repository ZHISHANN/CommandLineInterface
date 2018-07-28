#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

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

/*HistoryBuffer *buffer(int length)
{
  HistoryBuffer *historyBuffer;
  historyBuffer->curent_index = 0;
  historyBuffer->previous_index = 0;
  historyBuffer->next_index = 0;
  historyBuffer->length = length;

  return historyBuffer;
}*/

//copy the string to another place
char *processKeyPress(char *key)
{
  char *string;
  string = malloc(strlen(key)+1);

  strcpy(string,key);

  return string;
}

//get the index of the end of string
int indexOfString(char *string)
{
  int len;

  len = strlen(string);
  return len;
}

void processBackspace(char *line)
{
  while(line != NULL)
  {
    
  }
}

void MoveLeft()
{

}

void MoveRight()
{

}

char recallPrevious()
{

}

char recallNext()
{

}
