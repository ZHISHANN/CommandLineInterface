#include "CLI.h"
#include "LinkedList.h"
#include "UserDefined.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <malloc.h>

/*limit the history storage*/
int Max_History = 3;

/*
*  1. create a dynamic location to store data from line buffer
*  2. call function createListItem to allocate the next,previous and data
*  3. add the detail return form (2) to linked list by calling funtion linkedListAddToTail
*  4. if count exceed limitation of history
*  5. remove the first record from linked list by calling funtion linkedListRemoveFromHead
*/
void processLine(LinkedList *list, Line *line)
{
  char *input = malloc(4096);
  while(line->buffer[line->index] != '\0')
    line->index++;
  strcpy(input, line->buffer);
  ListItem *item = createListItem((void *)(input));
  linkedListAddToTail(list,item);

  if(list->count > Max_History)
    linkedListRemoveFromHead(list);
}

/*
*  1. check the index must not equal to 0
*  2. check the wheather the index is equal to last index or not
*  3. if not, replace all the data in index with the data of next of the index
*  4. put a NULL to data in index when index was larger than last index
*  5. if index and last index was equal, decrease index by 1 and put in NULL
*/
void processBackspace(Line *line)
{
  int index = line->index - 1;
  int current_index = line->index;
  line->last_index = strlen(line->buffer);

  if (line->index >= 0)
  {
    if(line->index != line->last_index)
    {
      while(line->index < line->last_index)
      {
        line->buffer[index] = line->buffer[line->index];
        line->index++;
        index = line->index - 1;
      }
      line->index--;
      line->buffer[line->index] = '\0';
      current_index--;
      line->index = current_index;
    }
    else
    {
      line->index--;
      line->buffer[line->index] = '\0';
    }
  }

  if(line->index <= 0)
    line->index = 0;
}

/*
*  1. check the user input
*  2. decrease line index if line index does not reach 0
*  3. set line index cannot less than 0
*/
void moveLeft(Line *line)
{
  line->last_index = strlen(line->buffer);

  if(line->buffer == '\0')
    line->index = 0;

  if(line->index != 0)
    line->index--;
  else
    line->index = 0;
}

/*
*  1. incease index if line index does not exceed last index of buffer
*  2. set line index cannot exceed last index
*/
void moveRight(Line *line)
{
  line->last_index = strlen(line->buffer);

  if(line->buffer[line->index] != '\0')
    line->index++;
}

/*
*  1. assign every character to buffer
*  2. assign '\0' to end of every buffer
*/
void writeToBuffer(Line *line, char ch)
{
  if(ch != '\0' || line->index != line->last_index)
  {
    line->buffer[line->index] = ch;
    line->index++;
  }
  line->last_index = strlen(line->buffer);
  line->buffer[line->last_index] = '\0';
}

/* 1. update last index, when index move to front
*  2. to remember the length of the buffer
*  3. for clear buffer function
*  4. to know how many to clear
*/
void clearBuffer(Line *line)
{
  int i;
  line->last_index = strlen(line->buffer);
  for(i = 0; i < line->last_index; i++)
  {
    line->buffer[i] = '\0';
    line->index--;
  }
  if(line->index <= 0)
    line->index = 0;
}

/*
*  1. check the input data
*  2. copy every input data to buffer
*/
void copyStringToLine(Line *line, char *str)
{
  if(str != '\0')
  {
    strcpy(line->buffer, str);
    line->index = line->last_index = strlen(str);
    line->buffer[line->index] = '\0';
  }
}
