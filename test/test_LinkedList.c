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
//tail---^                   tail-----------------^
//count = 1                  count = 2
void xtest_LinkedListAddToTail_given_next_value_expect_item_inserted(void)
{
    int value1 = 1, value2 = 2;
    int *addr;
    ListItem item1 = {(void *)&value1, NULL};
    ListItem item2 = {(void *)&value2, NULL};
    LinkedList list = {&item1, NULL, 1};

    addr = LinkedListAddToTail(&list,&item2);
    ListItem *check_data;
    check_data = &addr;

    TEST_ASSERT_EQUAL(&item1, list.head);
    TEST_ASSERT_EQUAL(addr, list.tail);
    TEST_ASSERT_EQUAL(NULL, item2.next);
    TEST_ASSERT_EQUAL(addr, item1.next);
    //TEST_ASSERT_EQUAL(2,check_data->next->data);          //check the content
    TEST_ASSERT_EQUAL(2, list.count);
}

//starting from an empty linked list, add item 1 into it
//before       after
//head--       head -->item
//     /               next--/
//tail--       tail----^    /
//     /
//count = 0    count = 1
void xtest_LinkedListAddToTail_given_an_empty_inked_list_add_1_to_head_expect_item_inserted(void)
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
//head->item1    item2               head->item2    item1
//      next-----^  next--/                next--/  next--/
//tail->item2                        tail->item2
//count = 2                          count = 1
void xtest_LinkedListRemoveFromHead_given_item1_and_item2_with_delete_item1_expected_left_item2(void)
{
  int value1 = 23, value2 = 9;
  int *addr;
  ListItem item2 = {(void *)&value2, NULL};
  ListItem item1 = {(void *)&value1, &item2};
  LinkedList list = {&item1, &item2, 2};

  addr = LinkedListRemoveFromHead(&list);

  TEST_ASSERT_EQUAL(&item2, list.head);
  TEST_ASSERT_EQUAL(&item2, list.tail);
  TEST_ASSERT_EQUAL(NULL, item2.next);
  TEST_ASSERT_EQUAL(NULL, item1.next);
  TEST_ASSERT_EQUAL(1, list.count);
}

void xtest_processKeyPress_given_empty_list_expect_string_inserted(void)
{
  char *key = "hello";
  char *string = processKeyPress(key);

  TEST_ASSERT_EQUAL_STRING("hello",string);
}

//backspace for 1 time
//before               after
//"happy"              "happ"
void test_processBackspace_given_happy_and_backspace_1_time_expect_happ(void)
{
  char buffer[1024] = "happy";

  Line line = {buffer,NULL,NULL};

  processBackspace(&line);

  TEST_ASSERT_EQUAL(NULL,line.last_index);
  TEST_ASSERT_EQUAL(3,line.index);
}
