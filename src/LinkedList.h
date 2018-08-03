#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#define Max_Value 20             //limit the size of count
#define MAX_BUFFER_SIZE 4096

typedef struct ListItem ListItem;
struct ListItem{
  void *data;
  ListItem *next;
  ListItem *prev;
};

typedef struct LinkedList LinkedList;
struct LinkedList{
  ListItem *head;
  ListItem *tail;
  int count;
};

typedef struct Line Line;
struct Line{
  void *buffer;
  int index;
  int last_index;
};

ListItem *LinkedListRemoveFromHead(LinkedList *list);
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
//ListItem *(*FuncPtr)(void data);
ListItem *CreateListItem(void *data);
//void ProcessLine (void(*FuncPtr)(void *obj, char *line), void *obj);
char *processKeyPress(char *key);
void processBackspace(Line *line);
void MoveLeft();
void MoveRight();
void *recallPrevious(LinkedList *list);
void *recallNext();
//void PrintTillIndex(int Index);
//void printBufferTill(char buffer[], int length)
int indexOfString(Line *line);
void resetRecalledItem(LinkedList *list);

#endif // _LINKEDLIST_H
