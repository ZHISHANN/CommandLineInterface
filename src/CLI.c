#include "CLI.h"
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

//copy the string to another place
/*char *processKeyPress(char *key)//processLine
{
  char *string;
  string = malloc(strlen(key)+1);

  strcpy(string,key);

  return string;
}*/

void processLine(Line *line)
{
  char *input = strdup(line->buffer);
  ListItem item = {(void *)input, NULL};
  LinkedList list = {&item, NULL, 0};
  int *addr = LinkedListAddToTail(&item, &input);
}

void processBackspace(Line *line)
{
  //int endofinput = strlen(line->buffer);

  /*if(line->index == 0 && line->last_index == 0)
  {
    line->last_index = endofinput;
    line->index = endofinput;
  }*/

  line->index--;
  line->buffer[line->index] = '\0';

  if(line->index < 0)
    line->index = 0;
}

void printBufferTill(char buffer[], int length)
{
	int i;

	for(i=0; i<=length ;i++)
	{
		printf("%c", buffer[i]);
	}
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
