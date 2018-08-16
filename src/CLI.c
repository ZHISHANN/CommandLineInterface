#include "CLI.h"
#include "LinkedList.h"
#include "UserDefined.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

void processLine(LinkedList *list, Line *line)
{
  char *input = strdup(line->buffer);
  ListItem *item = CreateListItem((void *)input);
  LinkedListAddToTail(list,item);

  if(list->count > Max_History)
  {
    list->head = list->head->next;
    list->count--;
    LinkedListAddToTail(list,item);
  }
}

void processBackspace(Line *line)
{
  line->index--;
  line->buffer[line->index] = '\0';

  if(line->index < 0)
    line->index = 0;
}

void moveLeft(Line *line)
{
  if (line->index <= 0)
    line->index = 0;
  else
    line->index--;
}

void moveRight(Line *line)
{
  if (line->index == 0 && line->last_index == 0)
    line->last_index = strlen(line->buffer);

  if (line->index >= line->last_index)
    line->index = line->last_index;
  else
    line->index++;
}

void writeToBuffer(Line *line, char ch)
{
  line->buffer[line->index] = ch;
  line->index++;
  line->buffer[line->index] = '\0';
  line->last_index = line->index;
}

//update last index
//when index move to front
//to remember the length of the buffer
//for clear buffer function
//to know how many to clear
void clearBuffer(Line *line)
{
  line->last_index = line->index;
  line->index = 0;
  line->buffer[line->index] = '\0';
}

void copyStringToLine(Line *line, char *str)
{
  strcpy(line->buffer, str);
  line->index = strlen(str);
  line->buffer[line->index] = '\0';
}

/*void printBufferTill(Line *line)
{
	for(int i=0; i<=line->index ;i++)
	{
		printf("%c", line->buffer[i]);
	}
}*/
