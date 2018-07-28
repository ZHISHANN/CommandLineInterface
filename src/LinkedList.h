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
  char *buffer;
  int index;
  int last_index;
};

typedef struct HistoryBuffer HistoryBuffer;
struct HistoryBuffer{
  int current_index;
  int previous_index;
  int next_index;
  int length;
};

ListItem *LinkedListRemoveFromHead(LinkedList *list);
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
ListItem *(*FuncPtr)(void data);
ListItem *CreateListItem(void * data);
HistoryBuffer *buffer(int length);
//void ProcessLine (void(*FuncPtr)(void *obj, char *line), void *obj);
char *ProcessKeyPress(char *key);
//void Processbackspace();
char *processBackspace(char *string, int enter);
void MoveLeft();
void MoveRight();
char recallPrevious();
char recallNext();
void PrintTillIndex(int Index);
int indexOfString(char *string);

#endif // _LINKEDLIST_H
