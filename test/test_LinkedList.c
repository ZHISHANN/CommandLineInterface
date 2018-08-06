#include "unity.h"
#include "LinkedList.h"
#include "CLI.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

void setUp(void){}

void tearDown(void){}

void test_LinkedListAddToTail_given_3_value_expect_next_item_inserted(void)
{
    int value1 = 1, value2 = 2, value3 = 23;
    ListItem item3 = {(void *)&value3, NULL};
    ListItem item2 = {(void *)&value2, &item3};
    ListItem item1 = {(void *)&value1, &item2};
    LinkedList list = {&item1, &item3, 3};

    TEST_ASSERT_EQUAL(&item1, list.head);
    TEST_ASSERT_EQUAL(&item3, list.tail);
    TEST_ASSERT_EQUAL(NULL, item3.next);
    TEST_ASSERT_EQUAL(&item3, item2.next);
    TEST_ASSERT_EQUAL(3, list.count);
}

//before                               after
//head-->item1     item2               head->item1   item2     item3
//       next------^  next--/                next----^  next---^  next--/
//tail-------------^                   tail--------------------^
//count = 2                            count = 3
void test_LinkedListAddToTail_given_2_value_expect_next_item_inserted(void)
{
    int value1 = 1, value2 = 2, value3 = 23;
    int *addr;
    ListItem item2 = {(void *)&value2, NULL};
    ListItem item1 = {(void *)&value1, &item2};
    ListItem item3 = {(void *)&value3};
    LinkedList list = {&item1, &item2, 2};

    addr = LinkedListAddToTail(&list,&item3);

    TEST_ASSERT_EQUAL(&item1, list.head);
    TEST_ASSERT_EQUAL(addr, list.tail);
    TEST_ASSERT_EQUAL(NULL, item3.next);
    TEST_ASSERT_EQUAL(addr, item2.next);
    TEST_ASSERT_EQUAL(3, list.count);
    //TEST_ASSERT_EQUAL_STRING(item3.data, addr);
}

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

    TEST_ASSERT_EQUAL(&item1, list.head);
    TEST_ASSERT_EQUAL(addr, list.tail);
    TEST_ASSERT_EQUAL(NULL, item2.next);
    TEST_ASSERT_EQUAL(addr, item1.next);
    TEST_ASSERT_EQUAL(2, list.count);
    //TEST_ASSERT_EQUAL_STRING(item2.data, addr);
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
    //TEST_ASSERT_EQUAL_STRING(item.data, addr);
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

//before                                  after
//head->item1    item2    item3           head->item2   item3
//      next-----^  next--^                     next----^  next--/
//tail->item3                             tail->item3
//count = 3                          count = 2
void test_LinkedListRemoveFromHead_given_item1_and_item2_and_item3_with_delete_item1_expected_left_item2_and_item3(void)
{
  int value1 = 23, value2 = 9, value3 = 18;
  ListItem item3 = {(void *)&value3, NULL};
  ListItem item2 = {(void *)&value2, &item3};
  ListItem item1 = {(void *)&value1, &item2};
  LinkedList list = {&item1, &item3, 3};

  LinkedListRemoveFromHead(&list);

  TEST_ASSERT_EQUAL(&item2, list.head);
  TEST_ASSERT_EQUAL(&item3, list.tail);
  TEST_ASSERT_EQUAL(NULL, item3.next);
  TEST_ASSERT_EQUAL(&item3,item2.next);
  TEST_ASSERT_EQUAL(NULL, item1.next);
  TEST_ASSERT_EQUAL(2, list.count);
}

/* recall previous 1 time
* before                            after
* head->item1         item2         head->item1      item2
*      next-----------^  next--/          next-------^  next--/
*      prev--/           prev--/          prev->item2   prev->item1
* tail->item2                       tail->item2
*/
void test_recallPrevious_given_item1_and_item2_then_recallPrevious_at_item1_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)&buffer2, NULL, NULL};
  ListItem item1 = {(void *)&buffer1, &item2, &item2};
  LinkedList list = {&item1, &item1, 2};   //because of the tail
  item2.next = &item1;
  item2.prev = &item1;

  //TEST_ASSERT_EQUAL_STRING("hi", recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING(item2.data, recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING("hello", recallPrevious(&list));   //should be hi here
  //TEST_ASSERT_EQUAL(recallPrevious(&list), item2.prev);
  //TEST_ASSERT_EQUAL(recallPrevious(&list), item1.prev);
}

void test_recallPrevious_given_item1_and_item2_then_recallPrevious_at_item2_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  ListItem item2 = {(void *)&buffer2, NULL, NULL};
  ListItem item1 = {(void *)&buffer1, &item2, &item2};
  LinkedList list = {&item2, &item2, 2};
  item2.next = &item1;
  item2.prev = &item1;

  TEST_ASSERT_EQUAL_STRING(item1.data, recallPrevious(&list));
  TEST_ASSERT_EQUAL_STRING("hi", recallPrevious(&list));  //should be hello here
}
/* recall previous 1 time
* before                                         after
* head->item1      item2         item3           head->item1      item2          item3
*      next--------^  next-------^  next--/            next-------^  next--------^  next--/
*      prev--/        prev--/       prev--/            prev->item3   prev->item1    prev->item2
* tail->item3                                    tail->item3
*/
void xtest_recallPrevious_given_item1_item2_item3_then_recall_previous_1_time_expect_item2_display(void)
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

//before                         after
//head->item1    item2           head->item1    item2
//      next-----^   next--/           next-----^   next->item1
//tail-->item2                   tail->item2
void test_recallNext_given_item1_and_item2_recallNext_at_item2_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *string_return;
  ListItem item2 = {(void *)&buffer2, NULL};
  ListItem item1 = {(void *)&buffer1, &item2};
  LinkedList list = {&item2, NULL, 2};
  item2.next = &item1;
  //ListItem recalledItem = item1;

  string_return = recallNext(&list);
  TEST_ASSERT_EQUAL_STRING(item1.data, string_return);
  //TEST_ASSERT_EQUAL_STRING("hi", string_return);
}

void test_recallNext_given_item1_and_item2_recallNext_at_item1_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *string_return;
  ListItem item2 = {(void *)&buffer2, NULL};
  ListItem item1 = {(void *)&buffer1, &item2};
  LinkedList list = {&item1, NULL, 2};
  item2.next = &item1;
  //ListItem recalledItem = item1;

  string_return = recallNext(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, string_return);
  //TEST_ASSERT_EQUAL_STRING("hi", string_return);
}

//before                               after
//head->item1   item2    item3         head->item1   item2    item3
//      next----^  next--^  next--/          next----^  next--^  next->item1
//tail--/                              tail->item3
void test_recallNext_given_item1_item2_item3_recallNext_at_tem3_expect_item1_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  char *string_return;
  ListItem item3 = {(void *)&buffer3, NULL};
  ListItem item2 = {(void *)&buffer2, &item3};
  ListItem item1 = {(void *)&buffer1, &item2};
  item3.next = &item1;
  //ListItem recalledItem = item1;
  LinkedList list = {&item3, NULL, 3};

  string_return = recallNext(&list);
  TEST_ASSERT_EQUAL_STRING(item1.data, string_return);

  //string_return = recallNext(&list);
  //TEST_ASSERT_EQUAL_STRING("hello", string_return);
  //string_return = recallNext(&list);
  //TEST_ASSERT_EQUAL_STRING("hi", string_return);
  //string_return = recallNext(&list);
  //TEST_ASSERT_EQUAL_STRING("hey", string_return);
}

void test_recallNext_given_item1_item2_item3_recallNext_at_item2_expect_item3_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  char *string_return;
  ListItem item3 = {(void *)&buffer3, NULL};
  ListItem item2 = {(void *)&buffer2, &item3};
  ListItem item1 = {(void *)&buffer1, &item2};
  item3.next = &item1;
  //ListItem recalledItem = item1;
  LinkedList list = {&item2, NULL, 3};

  string_return = recallNext(&list);
  TEST_ASSERT_EQUAL_STRING(item3.data, string_return);
}

void test_recallNext_given_item1_item2_item3_recallNext_at_item1_expect_item2_display(void)
{
  char *buffer1 = "hello";
  char *buffer2 = "hi";
  char *buffer3 = "hey";
  char *string_return;
  ListItem item3 = {(void *)&buffer3, NULL};
  ListItem item2 = {(void *)&buffer2, &item3};
  ListItem item1 = {(void *)&buffer1, &item2};
  item3.next = &item1;
  //ListItem recalledItem = item1;
  LinkedList list = {&item1, NULL, 3};

  string_return = recallNext(&list);
  TEST_ASSERT_EQUAL_STRING(item2.data, string_return);
}
