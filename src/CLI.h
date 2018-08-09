#ifndef _CLI_H
#define _CLI_H

#include "UserDefined.h"

typedef struct line line;
struct line{
  char buffer[BUFFER_SIZE];
  int index;
  int last_index;
};

//void ProcessLine (void(*FuncPtr)(void *obj, char *line), void *obj);
char *processKeyPress(char *key);
void processBackspace(line *Line);
void moveLeft(line *Line);
void moveRight(line *Line);
void printBufferTill(char buffer[], int length);
void writeToBuffer(line *Line, char ch);
void clearBuffer(line *Line);
void clearConsoleLine(line *Line, int num);
//ListItem *(*FuncPtr)(void data);

#endif // _CLI_H
