#ifndef _CLI_H
#define _CLI_H

typedef struct line line;
struct line{
  void *buffer;
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
//ListItem *(*FuncPtr)(void data);

#endif // _CLI_H
