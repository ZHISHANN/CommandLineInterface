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

void getTypedChars(void)
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
        displayContent(&line);
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

void getSpecialKey(void)
{
  /*uint8_t c;
  Line line = {{'s','m','i','l','e'},5};
  displayContent(&line);
  c = getch();

  do{
      moveLeft(&line);
  }
  while(c == ARROW_LEFT);*/
}
