#include "KeyAndConsole.h"
#include "LinkedList.h"
#include "CLI.h"
#include "main.h"
#include <stdio.h>

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
