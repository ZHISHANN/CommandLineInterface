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

void moveLeftOnConsole()
{
  printf("\b");
}

void moveRightOnConsole(Line *line)
{
  printf("%c",line->buffer[line->index]);
}

void getTypedChars(void)
{
  uint8_t c;
  Line line = {{'\0'},0,0};

  do{
    c = getch();
    if(c != ENTER)
    {
      writeToBuffer(&line, c);
      displayContent(&line);
    } else {
      clearConsoleLine(line.index);
      clearBuffer(&line);
    }
  }while(c != ENTER);
}

void getBackspace(void)
{
  uint8_t c;
  Line line = {{'\0'},0,0};

  do{
    c = getch();
    if(c != ENTER)
    {
      if(c == KEY_BACKSPACE)
      {
        backspaceOnConsole();
        writeToBuffer(&line, c);
      }
      else {
        writeToBuffer(&line, c);
        displayContent(&line);
      }
    } else {
      clearConsoleLine(line.index);
      clearBuffer(&line);
    }
  }while(c != ENTER);
}

void getMoveKey(void)
{
  uint8_t c, ac;
  Line line = {{'\0'},0,0};

  do{
    c = getch();

    if(c != ENTER)
    {
      if()
      {
        moveLeftOnConsole();
        moveLeft(&line);
      }
      else if ()
      {
        moveRightOnConsole(&line);
        moveRight(&line);
      }
      else
      {
        writeToBuffer(&line, c);
        displayContent(&line);
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
}
