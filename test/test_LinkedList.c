#include "unity.h"
#include "LinkedList.h"
#include "CLI.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

void setUp(void){}

void tearDown(void){}

/* Started from an empty linked list, add item 1 into it
*  before        after
*  head--/       head -->item
*       /               next--/
*  tail--/       tail----^
*  count = 0     count = 1
*/
void test_linkedListAddToTail_given_an_empty_inked_list_add_1_to_head_expect_item_inserted(void)
{
    char *buffer = "hello";
    ListItem item = {(void *)buffer};
    LinkedList list = {NULL, NULL, 0};      //head tail count

    linkedListAddToTail(&list,&item);

    TEST_ASSERT_EQUAL_STRING("hello", list.head->data);
    TEST_ASSERT_EQUAL_STRING("hello", list.tail->data);
    TEST_ASSERT_EQUAL(item.data, list.head->data);
    TEST_ASSERT_EQUAL(item.data, list.tail->data);
    TEST_ASSERT_EQUAL(item.data, list.head->next->data);
    TEST_ASSERT_EQUAL(item.data, list.head->prev->data);
    TEST_ASSERT_EQUAL(item.data, list.tail->next->data);
    TEST_ASSERT_EQUAL(item.data, list.tail->prev->data);
    TEST_ASSERT_EQUAL(1, list.count);
}

/* Started with one item inserted
*  before                     after
*  head-->item1               head-->item1     item2
*        next--/                    next------^  next--/
*  tail---^                   tail-------------^
*  count = 1                  count = 2
*/
void test_linkedListAddToTail_given_next_character_expect_item_inserted(void)
{
    char *buffer1 = "hello";
    char *buffer2 = "hi";
    ListItem item1 = {(void *)buffer1};
    ListItem item2 = {(void *)buffer2};
    LinkedList list = {&item1, &item1, 1};

    linkedListAddToTail(&list,&item2);

    TEST_ASSERT_EQUAL_STRING("hello", list.head->data);
    TEST_ASSERT_EQUAL_STRING("hi", list.tail->data);
    TEST_ASSERT_EQUAL(item1.data, list.head->data);
    TEST_ASSERT_EQUAL(item2.data, list.tail->data);
    TEST_ASSERT_EQUAL(item2.data, list.head->next->data);
    TEST_ASSERT_EQUAL(item2.data, list.head->prev->data);
    TEST_ASSERT_EQUAL(item1.data, list.tail->next->data);
    TEST_ASSERT_EQUAL(item1.data, list.tail->prev->data);
    TEST_ASSERT_EQUAL(2, list.count);
}

/* Started with two item inserted
*  before                               after
*  head-->item1     item2               head->item1   item2     item3
*        next------^  next--/                next----^  next---^  next--/
*  tail-------------^                   tail--------------------^
*  count = 2                            count = 3
*/
void test_linkedListAddToTail_given_3_character_expect_next_item_inserted(void)
{
    char *buffer1 = "hello";
    char *buffer2 = "hi";
    char *buffer3 = "hey";
    ListItem item3 = {(void *)buffer3};
    ListItem item2 = {(void *)buffer2};
    ListItem item1 = {(void *)buffer1, &item2};
    LinkedList list = {&item1, &item2, 2};
    item2.prev = &item1;

    linkedListAddToTail(&list,&item3);

    TEST_ASSERT_EQUAL_STRING("hello", list.head->data);
    TEST_ASSERT_EQUAL_STRING("hey", list.tail->data);
    TEST_ASSERT_EQUAL(item1.data, list.head->data);
    TEST_ASSERT_EQUAL(item3.data, list.tail->data);
    TEST_ASSERT_EQUAL(item2.data, list.head->next->data);
    TEST_ASSERT_EQUAL(item3.data, list.head->next->next->data);
    TEST_ASSERT_EQUAL(item1.data, list.tail->next->data);
    TEST_ASSERT_EQUAL(item2.data, list.tail->prev->data);
    TEST_ASSERT_EQUAL(item1.data, list.tail->prev->prev->data);
    TEST_ASSERT_EQUAL(item3.data, list.head->prev->data);
    TEST_ASSERT_EQUAL(3, list.count);
}

/* Started with an empty list
*  before                after
*  head--/               head--/
*    next--/               next--/
*  tail--/               tail--/
*  count = 0             coutn = 0
*/
void test_linkedListRemoveFromHead_given_empty_list(void)
{
  LinkedList list = {NULL, NULL, 0};
  linkedListRemoveFromHead(&list);

  TEST_ASSERT_EQUAL(NULL, list.head);
  TEST_ASSERT_EQUAL(NULL, list.tail);
  TEST_ASSERT_EQUAL(0, list.count);
}

/* Started with 1 item and remove it from list
*  before                   after
*  head->item               head--/
*        next--/                  next--/
*  tail->item               tail--/
*  count = 1                count = 0
*/
void test_linkedListRemoveFromHead_given_1_item_expect_NULL(void)
{
  char *buffer = "hello";
  ListItem item1 = {(void *)buffer, NULL};
  LinkedList list = {&item1, &item1, 1};

  linkedListRemoveFromHead(&list);

  TEST_ASSERT_EQUAL(NULL, list.head);
  TEST_ASSERT_EQUAL(NULL, list.tail);
  TEST_ASSERT_EQUAL(0, list.count);
}

/* Started with 2 item and remove the first item from list
*  before                             after
*  head->item1    item2               head->item2
*        next-----^  next--/                next--/
*  tail->item2                        tail->item2
*  count = 2                          count = 1
*/
void test_linkedListRemoveFromHead_given_item1_and_item2_with_delete_item1_expected_left_item2(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "smile";
  ListItem *addr;
  ListItem item2 = {(void *)buffer2};
  ListItem item1 = {(void *)buffer1, &item2, &item2};
  LinkedList list = {&item1, &item2, 2};
  item2.next = &item1;
  item2.prev = &item1;

  linkedListRemoveFromHead(&list);

  TEST_ASSERT_EQUAL_STRING("smile", list.head->data);
  TEST_ASSERT_EQUAL_STRING("smile", list.tail->data);
  TEST_ASSERT_EQUAL(item2.data, list.head->data);
  TEST_ASSERT_EQUAL(item2.data, list.tail->data);
  TEST_ASSERT_EQUAL(item2.data, list.head->next->data);
  TEST_ASSERT_EQUAL(item2.data, list.tail->prev->data);
  TEST_ASSERT_EQUAL(1, list.count);
}

/* Started with 3 item and remove first item from list
*  before                                  after
*  head->item1    item2    item3           head->item2   item3
*        next-----^  next--^   next--/           next----^  next--/
*  tail->item3                             tail->item3
*  count = 3                               count = 2
*/
void test_linkedListRemoveFromHead_given_char_type_item1_and_item2_and_item3_with_delete_item1_expected_left_item2_and_item3(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  ListItem item3 = {(void *)buffer3, NULL};
  ListItem item2 = {(void *)buffer2, &item3};
  ListItem item1 = {(void *)buffer1, &item2, &item3};
  LinkedList list = {&item1, &item3, 3};
  item2.prev = &item1;
  item3.next = &item1;
  item3.prev = &item2;

  linkedListRemoveFromHead(&list);

  TEST_ASSERT_EQUAL_STRING("hi", list.head->data);
  TEST_ASSERT_EQUAL_STRING("hey", list.tail->data);
  TEST_ASSERT_EQUAL(item2.data, list.head->data);
  TEST_ASSERT_EQUAL(item3.data, list.tail->data);
  TEST_ASSERT_EQUAL(item3.data, list.head->next->data);
  TEST_ASSERT_EQUAL(item3.data, list.head->prev->data);
  TEST_ASSERT_EQUAL(item2.data, list.tail->next->data);
  TEST_ASSERT_EQUAL(item2.data, list.tail->prev->data);
  TEST_ASSERT_EQUAL(2, list.count);
}

/* recall previous 1 time
*  head->item1         item2
*       next-----------^  next->item1
*       prev->item2   prev->item1
*  tail->item2
*/
void test_recallPrevious_given_item1_and_item2_then_recallPrevious_1_time_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)buffer2, NULL, NULL};
  ListItem item1 = {(void *)buffer1, &item2, &item2};
  LinkedList list = {&item1, &item2, 2};
  item2.next = &item1;
  item2.prev = &item1;

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING("hi", recallPrevious(&list));

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, recallPrevious(&list));
}

void test_recallPrevious_given_item1_and_item2_then_recallPrevious_2_time_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)buffer2, NULL, NULL};
  ListItem item1 = {(void *)buffer1, &item2, &item2};
  LinkedList list = {&item1, &item2, 2};
  item2.next = &item1;
  item2.prev = &item1;

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING("hi", recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING("hello", recallPrevious(&list));

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING(item1.data, recallPrevious(&list));
}

void test_recallPrevious_given_item1_and_item2_then_recallPrevious_3_time_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)buffer2, NULL, NULL};
  ListItem item1 = {(void *)buffer1, &item2, &item2};
  LinkedList list = {&item1, &item2, 2};
  item2.next = &item1;
  item2.prev = &item1;

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING("hi", recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING("hello", recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING("hi", recallPrevious(&list));

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING(item1.data, recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING(item2.data, recallPrevious(&list));
}

/* recall previous 3 time
* before
* head->item1      item2         item3
*      next--------^  next-------^  next->item1
*      prev->item3   prev->item1    prev->item2
* tail->item3
*/
void test_recallPrevious_given_item1_item2_item3_then_recall_previous_3_time_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  ListItem item3 = {(void *)buffer3, NULL, NULL};
  ListItem item2 = {(void *)buffer2, &item3, NULL};
  ListItem item1 = {(void *)buffer1, &item2, &item3};
  LinkedList list = {&item1, &item3, 3};
  item2.prev = &item1;
  item3.next = &item1;
  item3.prev = &item2;

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING("hey", recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING("hi", recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING("hello", recallPrevious(&list));

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING(item3.data, recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING(item2.data, recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING(item1.data, recallPrevious(&list));
}

/* recallNext 1 time
*  before
*  head->item1    item2
*        next-----^   next->item1
*  tail-->item2
*/
void test_recallNext_given_item1_and_item2_recallNext_1_time_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)buffer2, NULL};
  ListItem item1 = {(void *)buffer1, &item2};
  LinkedList list = {&item1, &item2, 2};
  item2.next = &item1;

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, recallNext(&list));

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING("hi", recallNext(&list));
}

void test_recallNext_given_item1_and_item2_recallNext_3_time_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)buffer2, NULL};
  ListItem item1 = {(void *)buffer1, &item2};
  LinkedList list = {&item1, &item2, 2};
  item2.next = &item1;

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING("hi", recallNext(&list));
  TEST_ASSERT_EQUAL_STRING("hello", recallNext(&list));
  TEST_ASSERT_EQUAL_STRING("hi", recallNext(&list));

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, recallNext(&list));
  TEST_ASSERT_EQUAL_STRING(item1.data, recallNext(&list));
  TEST_ASSERT_EQUAL_STRING(item2.data, recallNext(&list));
}

/*
*  before
*  head->item1   item2    item3
*        next----^  next--^  next->item1
*  tail->item3
*/
void test_recallNext_given_item1_item2_item3_recallNext_4_time_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  char *string_return;
  ListItem item3 = {(void *)buffer3, NULL};
  ListItem item2 = {(void *)buffer2, &item3};
  ListItem item1 = {(void *)buffer1, &item2};
  item3.next = &item1;
  LinkedList list = {&item1, &item3, 3};

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING("hi", recallNext(&list));
  TEST_ASSERT_EQUAL_STRING("hey", recallNext(&list));
  TEST_ASSERT_EQUAL_STRING("hello", recallNext(&list));
  TEST_ASSERT_EQUAL_STRING("hi", recallNext(&list));

  resetRecalledItem(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, recallNext(&list));
  TEST_ASSERT_EQUAL_STRING(item3.data, recallNext(&list));
  TEST_ASSERT_EQUAL_STRING(item1.data, recallNext(&list));
  TEST_ASSERT_EQUAL_STRING(item2.data, recallNext(&list));
}
