#include "KeyAndConsole.h"
#include "LinkedList.h"
#include "CLI.h"
#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <conio.h>

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

void insertTab(Line *line)
{
  int num = 0;

  while(num <= 4)
  {
    writeToBuffer(line, ' ');
    num++;
  }
}

void moveLeftOnConsole()
{
  printf("\b");
}

void moveRightOnConsole(Line *line)
{
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
  LinkedList list = {&item1, &item2, 1};
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
            moveLeftOnConsole();
            moveLeft(&line);
          }
          else if(ac == ARROW_RIGHT)
          {
            moveRightOnConsole(&line);
            moveRight(&line);
          }
          else if(ac == ARROW_UP)
          {
            char *prev_str = recallPrevious(&list);
            strcpy(line.buffer, prev_str);
            line.index = strlen(prev_str);
            clearConsoleLine(line.index);
            displayContent(&line);
          }
          else if(ac == ARROW_DOWN)
          {
            char *next_str = recallNext(&list);
            strcpy(line.buffer, next_str);
            line.index = strlen(next_str);
            clearConsoleLine(line.index);
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
      else
      {
        writeToBuffer(&line, c);
        displayContent(&line);
        processLine(&list, &line);
      }
    }
    else
    {
      clearConsoleLine(line.index);
      clearBuffer(&line);
    }
  }while(c != ENTER);
}

int isEscapeKey(int code)
{
  if (code == 224 || code == 0)
    return 1;
  else
    return 0;
}
