#include "main.h"
#include "KeyAndConsole.h"
#include "CLI.h"
#include <stdio.h>
#include <stdint.h>
#include <conio.h>

void getTypedChars(void);
void getKeyPressed(void);
void getSpecialKey(void);

int main()
{
  printf("Hello\n");
  getTypedChars();
}

/*void getKeyPressed(void)  {
  uint8_t ac, c = '\n';
  c = getch(); //button pressed

  if (c == 13 || c == 0)
    ac = getch();

  printf("%c (%d) has been pressed\n",c,c);
  if (c == 13 || c == 0)
    printf("%c (%d) the actual character pressed\n",ac ,ac);
}*/

void getTypedChars(void)
{
  uint8_t c;
  Line line = {'\0',1,1};
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

void getSpecialKey(void)
{
  
}
