#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

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

ListItem *LinkedListRemoveFromHead(LinkedList *list);
ListItem *CreateListItem(void *data);
LinkedList *CreateLinkedList();
ListItem *(*FuncPtr)(void data);
ListItem *createListItem(void data);
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
void ProcessKeyPress(char key);
void ProcessLine (void(*FuncPtr)(void *obj, char *line), void *obj);
void Processbackspace();
void MoveLeft();
void MoveRight();
char recallPrevious();
char recallNext();
void PrintTillIndex(int Index);

#endif // _LINKEDLIST_H
