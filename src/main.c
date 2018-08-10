#include "main.h"
#include "KeyAndConsole.h"
#include "CLI.h"
#include <stdio.h>
#include <stdint.h>
#include <conio.h>

void getTypedChars(void);
void getKeyPressed(void);

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
  char c;
  line Line = {{0},0,2};
  do{
  c = getch();
  if(c != ENTER)
  {
    writeToBuffer(&Line, c);
    displayContent(&Line);
  } else {
    clearConsoleLine(&Line,Line.index);
    clearBuffer(&Line);
  }
}while(c != ENTER);

}
