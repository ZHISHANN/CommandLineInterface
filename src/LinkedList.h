#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#define Max_Value 20             //limit the size of count

typedef struct ListItem ListItem;
struct ListItem{
  void *data;
  ListItem *next;
};

typedef struct LinkedList LinkedList;
struct LinkedList{
  ListItem *head;
  ListItem *tail;
  int count;
};

ListItem *LinkedListRemoveFromHead(LinkedList *list);
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
ListItem *(*FuncPtr)(void data);
ListItem *CreateListItem(void data);
void ProcessLine (void(*FuncPtr)(void *obj, char *line), void *obj);
int *ProcessKeyPress(LinkedList *list, ListItem *ItemToAdd);
void Processbackspace();
void MoveLeft();
void MoveRight();
char recallPrevious();
char recallNext();
void PrintTillIndex(int Index);

#endif // _LINKEDLIST_H
