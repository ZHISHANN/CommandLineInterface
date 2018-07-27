#include "unity.h"
#include "LinkedList.h"

void setUp(void){}

void tearDown(void){}

//before                     after
//head-->item1               head-->item1     item2
//       next--                     next------^  next--/
//tail---^                  tail-----------------^
//count = 1                 count = 2

void test_LinkedListAddToTail_given_expect_item_inserted(void)
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

//starting from linked list with item 1, add item 2 into it
//before             after
//head-->item1       head -->item2   item1
//       next--              next--> next--
//tail---^            tail-----------^
//
//count = 1          count = 2
/*void test_LinkedListAddToHead_given_expect_item_inserted(void)
{
    int value1 = 1, value2 = 2;
    ListItem *item1 = {NULL, (void *)&value1};
    ListItem *item2 = {NULL, (void *)&value2};
    LinkedList list = {item1, NULL, 1};

    LinkedListAddToHead(&list,item2);

    TEST_ASSERT_EQUAL(item2, list.head);
    TEST_ASSERT_EQUAL(item1, list.tail);
    TEST_ASSERT_EQUAL(item1, item2->next);
    TEST_ASSERT_EQUAL(NULL, item1->next);
    TEST_ASSERT_EQUAL(2, list.count);
}*/
