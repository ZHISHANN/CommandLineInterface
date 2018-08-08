#include "KeyAndConsole.h"
#include "LinkedList.h"
#include "CLI.h"
#include "main.h"
#include <stdio.h>

void backspaceOnConsole()
{
  printf("\b \b");
}

void displayContent(char buffer[])
{
  printf("\r%s",buffer);
  printf("\n");
}
