#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct ListItem ListItem;
struct ListItem{
  void *data;
  ListItem *next;
  //ListItem *prev;
};

typedef struct LinkedList LinkedList;
struct LinkedList{
  ListItem *head;
  ListItem *tail;
  int count;
};

//void LinkedListAddToHead(LinkedList *list, ListItem *ItemToAdd);
int *LinkedListAddToTail(LinkedList *list, ListItem *ItemToAdd);
ListItem *LinkedListRemoveFromHead(LinkedList *list);
//ListItem *LinkedListRemoveFromTail(LinkedList *list);
ListItem *CreateListItem(void *data);
LinkedList *CreateLinkedList();

#endif // _LINKEDLIST_H
