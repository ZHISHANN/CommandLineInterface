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
      NewList->data = ItemToAdd->data; // Link the data part
      NewList->next = NULL;
      list->count++;
      list->tail = NewList;
  }
  else
  {
    // Traverse to the last node
    while(travel->next != NULL)
        travel = travel->next;

    NewList->data = ItemToAdd->data; // Link the data part
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
  int len = strlen(line);

  if (line != NULL)
  {
    line->index = len;
    line->last_index = len + 1;
  }

  return line;
}

void processBackspace()
{
  Line *line;
  int endofinput;

	if(line == '\0')
	{
		endofinput = strlen(line->buffer);
		line->buffer[endofinput-1] = '\0';
	}

  indexOfString(line->buffer);
  //processKeyPress(line->buffer);

}

void printBufferTill(char buffer[], int length)
{
	int i;
	
	printf("\r");

	for(i=0; i<length;i++)
	{
		printf("%c", buffer[i]);
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
