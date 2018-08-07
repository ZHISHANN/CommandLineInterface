#include "CLI.h"
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

//copy the string to another place
char *processKeyPress(char *key)
{
  char *string;
  string = malloc(strlen(key)+1);

  strcpy(string,key);

  return string;
}

void processBackspace(line *Line)
{
  Line->buffer = *(int *)Line->buffer;
  int endofinput;
  endofinput = strlen(Line->buffer);
  line *temp_index = Line;

  temp_index->last_index = endofinput + 1;
  Line->last_index = endofinput;
  Line->index = endofinput;

	if(temp_index->last_index == '\0')
		Line->last_index = '\0';

  Line->index--;
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
  Line->buffer = *(int *)Line->buffer;
  int endofinput;
  endofinput = strlen(Line->buffer);

  Line->last_index = endofinput;
  Line->index = endofinput;

  if (Line->index == 1)
    Line->index = 1;
  else
    Line->index--;
}

void moveRight(line *Line)
{
  Line->buffer = *(int *)Line->buffer;
  int endofinput;
  endofinput = strlen(Line->buffer);

  Line->last_index = endofinput;

  if (Line->index >= Line->last_index)
    Line->index = endofinput;
  else
    Line->index++;
}
