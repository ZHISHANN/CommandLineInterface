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
  while(num != 0)
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
  Line line = {{'\0'},0,0};

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
        if(ac == ARROW_RIGHT)
        {
          moveRightOnConsole(&line);
          moveRight(&line);
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
      /*else if(c == ARROW_UP)
      {
        recallPrevious();
      }
      else if(c == ARROW_DOWN)
      {
        recallNext();
      }*/
      else
      {
        writeToBuffer(&line, c);
        displayContent(&line);
      }
    }
    else
    {
      //processLine(&line);
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
