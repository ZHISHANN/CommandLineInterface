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
      NewList->data = *(int *)ItemToAdd->data; // Link the data part
      NewList->next = NULL;
      list->count++;
      list->tail = NewList;
  }
  else
  {
    // Traverse to the last node
    while(travel->next != NULL)
        travel = travel->next;

    NewList->data = *(int *)ItemToAdd->data; // Link the data part
    NewList->next = NULL;
    list->count++;
    list->head->next = NewList;
    travel->next = NewList;   //link the address
    list->tail = NewList;
  }
  return NewList;
}

//copy the string to another place
char *processKeyPress(char *key)
{
  char *string;
  string = malloc(strlen(key)+1);

  strcpy(string,key);

  return string;
}

//get the index of the end of string
int indexOfString(Line *line)
{
  line->buffer = *(int *)line->buffer;
  int len = strlen(line->buffer);

  if (line != NULL)
  {
    line->index = len;
    line->last_index = len + 1;
  }
  return line;
}

void processBackspace(Line *line)
{
  line->buffer = *(int *)line->buffer;
  int endofinput;
  endofinput = strlen(line->buffer);
  Line *temp_index = line;

  temp_index->last_index = endofinput + 1;
  line->last_index = endofinput;
  line->index = endofinput;
  //line->index--;

	if(temp_index->last_index == '\0')
	{
		line->last_index = '\0';
    line->index--;
	}
}

/*void printBufferTill(char buffer[], int length)
{
	int i;

	printf("\r");

	for(i=0; i<length;i++)
	{
		printf("%c", buffer[i]);
	}
}*/

void MoveLeft()
{

}

void MoveRight()
{

}

char recallPrevious(LinkedList *list)
{
  ListItem *item = list->tail;

  //reach the head
  if(item->prev == list->head)
    item->prev = list->tail;
  else
    item = item->prev;

  return item;
}

char recallNext(LinkedList *list)
{
  ListItem *item = list->head;

  item = item->next;

  if(item->next == NULL)
    item->next = list->head;

  return item;
}
