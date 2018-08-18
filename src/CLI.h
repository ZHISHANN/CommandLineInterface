#ifndef _CLI_H
#define _CLI_H

#include "UserDefined.h"
#include "LinkedList.h"

typedef struct Line Line;
struct Line{
  char buffer[BUFFER_SIZE];
  int index;
  int last_index;
};

extern int Max_History;

char *processKeyPress(char *key);
void processBackspace(Line *line);
void moveLeft(Line *line);
void moveRight(Line *line);
void printBufferTill(Line *line);
void writeToBuffer(Line *line, char ch);
void clearBuffer(Line *line);
void processLine(LinkedList *list, Line *line);
void copyStringToLine(Line *line, char *str);
void moveCursorToEnd(Line *line);

#endif // _CLI_H
