#include "KeyAndConsole.h"
#include "LinkedList.h"
#include "CLI.h"
#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

/*
*  1. Initialize line as empty
*  2. pre-define some item in the linked list
*  3. get the user input
*  4. check th user input ctrl c key or not
*  5. if not, check the user input is enter or not
*  6. if not enter, check the user input is special key or not
*  7. after that, check user input is backspace/tab key/escape key/ctrl c key or not
*  8. do the relevant process for each user input
*  9. if user input enter, check the user input with an empty line or not
*  10. if user enter with an empty line, do not save it in buffer
*  11. else save the user input into buffer
*  12. if the user input ctrl c key, stop the process and get out from the loop
*/
void getKeyPressed(void)
{
  uint8_t c, ac;
  Line line = {{'\0'}, 0, 0};
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)buffer2};
  ListItem item1 = {(void *)buffer1, &item2, &item2};
  LinkedList list = {&item1, &item2, 2};
  item2.next = &item1;
  item2.prev = &item1;

  do{
    c = getch();

    if(c != ENTER)
    {
      if(isEscapeKey(c))
      {
          ac = getch();
          if(ac == ARROW_LEFT)
          {
            moveLeft(&line);
            displayCursor(&line);
          }
          else if(ac == ARROW_RIGHT)
          {
            moveRight(&line);
            displayCursor(&line);
          }
          else if(ac == ARROW_UP)
          {
            moveCursorToEnd(&line);
            clearPreviousRecord();
            copyStringToLine(&line, recallPrevious(&list));
            displayContent(&line);
          }
          else if(ac == ARROW_DOWN)
          {
            moveCursorToEnd(&line);
            clearPreviousRecord();
            copyStringToLine(&line, recallNext(&list));
            displayContent(&line);
          }
      }
      else if(c == KEY_BACKSPACE)
      {
        backspaceOnConsole();
        processBackspace(&line);
      }
      else if(c == KEY_TAB)
      {
        insertTab(&line);
        displayContent(&line);
        displayCursor(&line);
      }
      else if(c == ESC)
      {
        moveCursorToEnd(&line);
        clearPreviousRecord();
        clearBuffer(&line);
      }
      else if(c != CTRL_C)
      {
        writeToBuffer(&line, c);
        displayContent(&line);
      }
    }
    else
    {
      if(isLineEmpty(&line))
      {
        clearConsoleLine(line.index);
        clearBuffer(&line);
      }
      else
      {
        processLine(&list, &line);
        moveCursorToEnd(&line);
        clearPreviousRecord();
        clearBuffer(&line);
      }
    }
  }while(c != CTRL_C);
}

int isEscapeKey(int code)
{
  if (code == 224 || code == 0)
    return 1;
  else
    return 0;
}

int isLineEmpty(Line *line)
{
  int index = line->index;
  index--;
  do{
    if(line->buffer[index] == '\n' || line->buffer[index] == '\t' || line->buffer[index] == ' ' || line->buffer[index] == '\0')
      index--;
    else
      return 0;
  }while(line->buffer[index] != 0);

  return 1;
}

void moveCursorToEnd(Line *line)
{
  while(line->buffer[line->index] != '\0')
    line->index++;
}

void backspaceOnConsole()
{
  printf("\b \b");
}

void displayContent(Line *line)
{
  printf("\r%s", line->buffer);
}

void displayCursor(Line *line)
{
  printf("\r");
	for(int i = 0; i < line->index; i++)
	{
		printf("%c", line->buffer[i]);
	}
}

void clearConsoleLine(int num)
{
  while(num >= 0)
  {
    backspaceOnConsole();
    num--;
  }
}

void clearPreviousRecord()
{
	printf("\r");
	for(int i=0; i<79; i++)
	{
		printf(" ");
	}
  printf("\r");
}

/*
*  1. check the index is at the last index or not
*  2. if not, save all the character in the current index until the last index
*  3. do the tab process, with increase the index by 4
*  4. take out the character that save before tab process, save all of it to the buffer again
*  5. update the index
*/
void insertTab(Line *line)
{
  int num;
  int i, j;
  int index;
  index = strlen(line->buffer) + 4;
  char *temp_data;
  temp_data = malloc(4096);
  int current_index = line->index;

  if(line->index != strlen(line->buffer))
  {
    i = 0;
    do{
      temp_data[i] = line->buffer[current_index];
      current_index++;
      i++;
    }while(line->buffer[current_index] != '\0');
  }

  for(num = 0; num < 4; num++)
  {
    writeToBuffer(line, ' ');
  }

  i = 0;
  for(j = line->index; j < index; j++)
  {
    line->buffer[j] = temp_data[i];
    i++;
  }
}
