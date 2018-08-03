#include "unity.h"
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

void setUp(void){}

void tearDown(void){}

//before                     after
//head-->item1               head-->item1     item2
//       next--/                    next------^  next--/
//tail---^                   tail-------------^
//count = 1                  count = 2
void test_LinkedListAddToTail_given_next_value_expect_item_inserted(void)
{
    int value1 = 1, value2 = 2;
    int *addr;
    ListItem item1 = {(void *)&value1, NULL};
    ListItem item2 = {(void *)&value2, NULL};
    LinkedList list = {&item1, NULL, 1};

    addr = LinkedListAddToTail(&list,&item2);
    //ListItem *check_data;
    //check_data = &addr;

    TEST_ASSERT_EQUAL(&item1, list.head);
    TEST_ASSERT_EQUAL(addr, list.tail);
    TEST_ASSERT_EQUAL(NULL, item2.next);
    TEST_ASSERT_EQUAL(addr, item1.next);
    //TEST_ASSERT_EQUAL(2,check_data->next->data);          //check the content
    TEST_ASSERT_EQUAL(2, list.count);
}

//starting from an empty linked list, add item 1 into it
//before        after
//head--/       head -->item
//     /               next--/
//tail--/       tail----^
//     /
//count = 0     count = 1
void test_LinkedListAddToTail_given_an_empty_inked_list_add_1_to_head_expect_item_inserted(void)
{
    int value = 1;
    int *addr;
    LinkedList list = {NULL, NULL, 0};      //head tail count     //can create a function
    ListItem item = {(void *)&value, NULL};

    addr = LinkedListAddToTail(&list,&item);

    TEST_ASSERT_EQUAL(addr, list.head);
    TEST_ASSERT_EQUAL(addr, list.tail);
    TEST_ASSERT_EQUAL(NULL, item.next);
    TEST_ASSERT_EQUAL(1, list.count);
}

//before                             after
//head->item1    item2               head->item2
//      next-----^  next--/                next--/
//tail->item2                        tail->item2
//count = 2                          count = 1
void test_LinkedListRemoveFromHead_given_item1_and_item2_with_delete_item1_expected_left_item2(void)
{
  int value1 = 23, value2 = 9;
  ListItem item2 = {(void *)&value2, NULL};
  ListItem item1 = {(void *)&value1, &item2};
  LinkedList list = {&item1, &item2, 2};

  LinkedListRemoveFromHead(&list);

  TEST_ASSERT_EQUAL(&item2, list.head);
  TEST_ASSERT_EQUAL(&item2, list.tail);
  TEST_ASSERT_EQUAL(NULL, item2.next);
  TEST_ASSERT_EQUAL(NULL, item1.next);
  TEST_ASSERT_EQUAL(1, list.count);
}

void test_processKeyPress_given_empty_list_expect_string_inserted(void)
{
  char *key = "hello";
  int *addr;
  char *string = processKeyPress(key);
  LinkedList list = {NULL, NULL, 0};
  ListItem item = {(void *)&string, NULL};
  Line line = {(void *)&string, 0, 0};

  addr = LinkedListAddToTail(&list,&item);
  indexOfString(&line);

  TEST_ASSERT_EQUAL(5, line.index);
  TEST_ASSERT_EQUAL(6, line.last_index);
  TEST_ASSERT_EQUAL(addr, list.head);
  TEST_ASSERT_EQUAL(addr, list.tail);
  TEST_ASSERT_EQUAL(NULL, item.next);
  TEST_ASSERT_EQUAL_STRING("hello",string);
}

//backspace for 1 time
//before               after
//"happy"              "happ"
void test_processBackspace_given_happy_and_backspace_1_time_expect_happ(void)
{
  char *buffer = "happy";

  Line line = {(void *)&buffer, 0, 0};

  processBackspace(&line);

  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(4, line.index);
}

/* recall previous 1 time
* before                            after
* head->item1         item2         head->item1      item2
*      next-----------^  next--/          next-------^  next--/
*      prev--/           prev--/          prev->item2   prev->item1
* tail->item2                       tail->item2
*/
void test_recallPrevious_given_item1_and_item2_then_recall_previous_1_time_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)&buffer2, NULL, NULL};
  ListItem item1 = {(void *)&buffer1, &item2, NULL};
  LinkedList list = {&item1, &item2, 2};

  TEST_ASSERT_EQUAL(recallPrevious(&list), item2.prev);
  TEST_ASSERT_EQUAL(recallPrevious(&list), item1.prev);
}

/* recall previous 1 time
* before                                         after
* head->item1      item2         item3           head->item1      item2          item3
*      next--------^  next-------^  next--/            next-------^  next--------^  next--/
*      prev--/        prev--/       prev--/            prev->item3   prev->item1    prev->item2
* tail->item3                                    tail->item3
*/
void test_recallPrevious_given_item1_item2_item3_then_recall_previous_1_time_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  ListItem item3 = {(void *)&buffer3, NULL, NULL};
  ListItem item2 = {(void *)&buffer2, &item3, NULL};
  ListItem item1 = {(void *)&buffer1, &item2, NULL};
  LinkedList list = {&item1, &item3, 3};

  TEST_ASSERT_EQUAL(recallPrevious(&list), item1.prev);
  TEST_ASSERT_EQUAL(recallPrevious(&list), item2.prev);
  TEST_ASSERT_EQUAL(recallPrevious(&list), item3.prev);
}

void test_recallNext_given_item1_and_item2_recallNext_at_item1_expect_item1_then_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)&buffer2, NULL, NULL};
  ListItem item1 = {(void *)&buffer1, &item2, NULL};
  LinkedList list = {&item1, &item2, 2};

  item2.next = &item1;
  ListItem recalledItem = item1;

  TEST_ASSERT_EQUAL(item1.data, recallNext());
  TEST_ASSERT_EQUAL(item2.data, recallNext());
  TEST_ASSERT_EQUAL(item1.data, recallNext());
  //TEST_ASSERT_EQUAL(recallNext(&list), item2.next);
  //TEST_ASSERT_EQUAL(recallNext(&list), item1.next);
}

void xtest_recallNext_given_item1_item2_item3_recallNext_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  ListItem item3 = {(void *)&buffer3, NULL, NULL};
  ListItem item2 = {(void *)&buffer2, &item3, NULL};
  ListItem item1 = {(void *)&buffer1, &item2, NULL};
  LinkedList list = {&item1, &item3, 3};

  item3.next = &item1;
  ListItem recalledItem = item1;

  TEST_ASSERT_EQUAL(item1.data, recallNext());
  TEST_ASSERT_EQUAL(item2.data, recallNext());
  TEST_ASSERT_EQUAL(item3.data, recallNext());
  TEST_ASSERT_EQUAL(item1.data, recallNext());
}
