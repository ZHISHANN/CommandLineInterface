#include "CLI.h"
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

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
  int endofinput = strlen(Line->buffer);
  line *temp_index = Line;

  if(Line->index == 0 && Line->last_index == 0)
  {
    temp_index->last_index = endofinput + 1;
    Line->last_index = endofinput;
    Line->index = endofinput;
  }
  else
	 if(temp_index->last_index == '\0')
		Line->last_index = '\0';

  Line->index--;

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

/*void writeToBuffer(line *Line, char ch)
{
  Line->buffer = ch;

  int endofinput = strlen(Line->buffer);
  endofinput += 1;
  Line->last_index = endofinput;
  Line->last_index = '\0';
}*/

void clearBuffer(line *Line)
{
  int length = strlen(Line->buffer);
  Line->last_index = length;
  Line->index = 0;
}

void clearConsoleLine(line *Line, int num)
{
  while(num != 0)
  {
    processBackspace(Line);
    num--;
  }
}
