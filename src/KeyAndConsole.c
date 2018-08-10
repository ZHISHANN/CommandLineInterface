#include "KeyAndConsole.h"
#include "LinkedList.h"
#include "CLI.h"
#include "main.h"
#include <stdio.h>

void backspaceOnConsole()
{
  printf("\b \b");
}

void displayContent(line *Line)
{
  printf("\r%s\n",Line->buffer[Line->index]);
}

void clearConsoleLine(line *Line, int num)
{
  while(num != 0)
  {
    backspaceOnConsole();
    num--;
  }
}
