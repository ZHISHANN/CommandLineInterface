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

ListItem *linkedListRemoveFromHead(LinkedList *list);
ListItem *linkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
char *recallPrevious(LinkedList *list);
char *recallNext(LinkedList *list);
void resetRecalledItem(LinkedList *list);
ListItem *createListItem(void *data);
void linkedListInit(LinkedList *list);

#endif // _LINKEDLIST_H
