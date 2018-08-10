#ifndef _CLI_H
#define _CLI_H

#include "UserDefined.h"
//#include "LinkedList.h"

typedef struct line line;
struct line{
  char buffer[BUFFER_SIZE];
  int index;
  int last_index;
};

char *processKeyPress(char *key);
void processBackspace(line *Line);
void moveLeft(line *Line);
void moveRight(line *Line);
void printBufferTill(char buffer[], int length);
void writeToBuffer(line *Line, char ch);
void clearBuffer(line *Line);
//void clearConsoleLine(line *Line, int num);
void processLine(line *Line);

#endif // _CLI_H
