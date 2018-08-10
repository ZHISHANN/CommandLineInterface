#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "CLI.h"

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
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
char *recallPrevious(LinkedList *list);
char *recallNext(LinkedList *list);
int indexOfString(line *Line);
void resetRecalledItem(LinkedList *list);
ListItem *CreateListItem(void *data);


#endif // _LINKEDLIST_H
