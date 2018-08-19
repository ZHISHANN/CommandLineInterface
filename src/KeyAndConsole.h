#ifndef _KEYANDCONSOLE_H
#define _KEYANDCONSOLE_H

#include "CLI.h"

#define ARROW_UP 			    72
#define ARROW_DOWN  		  80
#define ARROW_LEFT 			  75
#define ARROW_RIGHT       77
#define KEY_BACKSPACE	 	   8
#define ENTER             13
#define KEY_TAB            9
#define ESC               27
#define CTRL_C             3

void backspaceOnConsole();
void displayContent(Line *line);
void clearConsoleLine(int num);
void moveLeftOnConsole(Line *line);
void moveRightOnConsole(Line *line);
void getKeyPressed(void);
int isEscapeKey(int code);
void insertTab(Line *line);
int isLineEmpty(Line *line);
void clearPreviousRecord();
void moveCursorToEnd(Line *line);

#endif // _KEYANDCONSOLE_H
