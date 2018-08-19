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

void processLine(LinkedList *list, Line *line);
void processBackspace(Line *line);
void moveLeft(Line *line);
void moveRight(Line *line);
void writeToBuffer(Line *line, char ch);
void clearBuffer(Line *line);
void copyStringToLine(Line *line, char *str);

#endif // _CLI_H
