#include "unity.h"
#include "LinkedList.h"

void setUp(void){}

void tearDown(void){}

//before                     after
//head-->item1               head-->item1     item2
//       next--/                    next------^  next--/
//tail---^                   tail-----------------^
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
    //TEST_ASSERT_EQUAL(9,item2.data);          //check the content
    TEST_ASSERT_EQUAL(2, list.count);
}

//starting from an empty linked list, add item 1 into it
//before       after
//head--       head -->item
//     /               next--/
//tail--       tail----^    /
//     /
//count = 0    count = 1
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

//overwrite data
//before                after
//head-->item           head-->item
//    next-->0               next-->0
//    data = 1               data = 9
//tail-->item                tail-->item
//count = 1                  count = 2
/*void test_ProcessKeyPress_given_input_expect_item_inserted(void)
{
  int value1 = 1, value2 = 9;
  int *addr;
  ListItem item1 = {(void *)&value1, 0};      //data    next
  ListItem item2 = {(void *)&value2, 0};
  LinkedList list = {&item1,,1};                //head tail count

  addr = ProcessKeyPress(&list, &item2);
  ListItem *check_data;
  check_data = &addr;

  TEST_ASSERT_EQUAL(0,list.count);          //check the index

  TEST_ASSERT_EQUAL(0,item2.next);
}*/
