#include "KeyAndConsole.h"
#include "LinkedList.h"
#include "CLI.h"
#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <ctype.h>

void backspaceOnConsole()
{
  printf("\b \b");
}

void displayContent(Line *line)
{
  printf("\r%s",line->buffer);
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

void insertTab(Line *line)
{
  int num = 0;

  while(num <= 4)
  {
    writeToBuffer(line, ' ');
    num++;
  }
}

void moveLeftOnConsole(Line *line)
{
  printf("\b");
}

void moveRightOnConsole(Line *line)
{
  if(line->buffer[line->index] != '\0')
    printf("%c",line->buffer[line->index]);
}

void getKeyPressed(void)
{
  uint8_t c, ac;
  Line line = {{'\0'}, 0, 0};
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)buffer2};
  ListItem item1 = {(void *)buffer1, &item2, &item2};
  LinkedList list = {&item1, &item2, 2};
  //LinkedList list = {NULL, NULL, 0};
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
            moveLeftOnConsole(&line);
            moveLeft(&line);
          }
          else if(ac == ARROW_RIGHT)
          {
            moveRightOnConsole(&line);
            moveRight(&line);
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
        clearConsoleLine(line.index);
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
  line->index--;
  do{
    if(line->buffer[line->index] == '\n' || line->buffer[line->index] == '\t' || line->buffer[line->index] == ' ' || line->buffer[line->index] == '\0')
      line->index--;
    else
      return 0;
  }while(line->buffer[line->index] != 0);

  return 1;
}

void moveCursorToEnd(Line *line)
{
  while(line->buffer[line->index] != '\0')
    line->index++;
}
