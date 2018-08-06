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
char *recallPrevious(LinkedList *list);
char *recallNext(LinkedList *list);
int indexOfString(Line *line);
void resetRecalledItem(LinkedList *list);
ListItem *CreateListItem(void *data);


#endif // _LINKEDLIST_H
