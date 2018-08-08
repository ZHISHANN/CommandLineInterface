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
  char *buff = (char *)Line->buffer;
  int endofinput = strlen(Line->buffer);
  line *temp_index = Line;

  if(Line->index == 0)
  {
    temp_index->last_index = endofinput + 1;
    Line->last_index = endofinput;
    Line->index = endofinput;
  }
  else
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
  char *buff = (char *)Line->buffer;
  int endofinput = strlen(Line->buffer);

  if (Line->index == 0)
  {
    Line->last_index = endofinput;
    Line->index = endofinput;
  }

  if (Line->index <= 1)
    Line->index = 1;
  else
    Line->index--;
}

void moveRight(line *Line)
{
  char *buff = (char *)Line->buffer;
  int endofinput = strlen(Line->buffer);

  if (Line->index == 0)
    Line->last_index = endofinput;

  if (Line->index >= Line->last_index)
    Line->index = endofinput;
  else
    Line->index++;
}

void writeToBuffer(line *Line, char ch)
{

}

void clearBuffer(line *Line)
{
  Line->index = 0;
}

void clearConsoleLine(int num)
{
  while(num != 0)
  {
    processBackspace();
    num--;
  }
}
