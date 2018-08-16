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
ListItem *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
char *recallPrevious(LinkedList *list);
char *recallNext(LinkedList *list);
void resetRecalledItem(LinkedList *list);
ListItem *CreateListItem(void *data);
void LinkedListInit(LinkedList *list);

#endif // _LINKEDLIST_H
