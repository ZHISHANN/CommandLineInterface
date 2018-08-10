#include "CLI.h"
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

//copy the string to another place
char *processKeyPress(char *key)//processLine
{
  char *string;
  string = malloc(strlen(key)+1);

  strcpy(string,key);

  return string;
}

void processLine(line *Line)
{
  char *input = strdup(Line->buffer);
  ListItem item = {(void *)input, NULL};
  LinkedList list = {&item, NULL, 0};
  int *addr = LinkedListAddToTail(&item, &input);
}

void processBackspace(line *Line)
{
  int endofinput = strlen(Line->buffer);

  if(Line->index == 0 && Line->last_index == 0)
  {
    Line->last_index = endofinput;
    Line->index = endofinput;
  }

  Line->index--;
  Line->buffer[Line->index] = '\0';

  if(Line->index <= 0)
    Line->index = 0;
}

void printBufferTill(char buffer[], int length)
{
	int i;

	for(i=0; i<=length ;i++)
	{
		printf("%c", buffer[i]);
	}
}

void moveLeft(line *Line)
{
  int endofinput = strlen(Line->buffer);

  if (Line->index == 0 && Line->last_index == 0)
  {
    Line->last_index = endofinput;
    Line->index = endofinput;
  }

  if (Line->index <= 0)
    Line->index = 0;
  else
    Line->index--;
}

void moveRight(line *Line)
{
  if (Line->index == 0 && Line->last_index == 0)
    Line->last_index = strlen(Line->buffer);

  if (Line->index >= Line->last_index)
    Line->index = Line->last_index;
  else
    Line->index++;
}

void writeToBuffer(line *Line, char ch)
{
  Line->buffer[Line->index] = ch;
  Line->index++;
  Line->last_index = strlen(Line->buffer) + 1;
  Line->buffer[Line->last_index] = '\0';
}

void clearBuffer(line *Line)
{
  Line->index = 0;
  Line->buffer[0] = '\0';
}
