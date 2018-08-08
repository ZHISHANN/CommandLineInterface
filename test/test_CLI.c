#include "unity.h"
#include "CLI.h"
#include "LinkedList.h"
#include "CLI.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

void setUp(void){}

void tearDown(void){}

void test_processKeyPress_given_item1_expect_string_copied(void)
{
  char *item1 = "hello";
  int *addr;
  char *string = processKeyPress(item1);
  LinkedList list = {NULL, NULL, 0};
  ListItem item = {(void *)string, NULL};
  line Line = {(void *)string, 0, 0};

  addr = LinkedListAddToTail(&list,&item);
  indexOfString(&Line);

  TEST_ASSERT_EQUAL(5, Line.index);
  TEST_ASSERT_EQUAL(6, Line.last_index);
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

  line Line = {(void *)buffer, 0, 0};

  processBackspace(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(4, Line.index);
}

void test_processBackspace_given_happy_and_backspace_2_time_expect_hap(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  processBackspace(&Line);
  processBackspace(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(3, Line.index);
}

void test_processBackspace_given_happy_and_backspace_3_time_expect_ha(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  processBackspace(&Line);
  processBackspace(&Line);
  processBackspace(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(2, Line.index);
}

void test_moveLeft_given_happy_and_move_left_1_time(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  moveLeft(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(4, Line.index);
}

void test_moveLeft_given_happy_and_move_left_5_time(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(1, Line.index);
}

void test_moveLeft_given_happy_and_move_left_6_time(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(1, Line.index);
}

void test_moveLeft_given_h_and_move_left_1_time(void)
{
  char *buffer = "h";
  line Line = {(void *)buffer, 0, 0};

  moveLeft(&Line);

  TEST_ASSERT_EQUAL(1, Line.last_index);
  TEST_ASSERT_EQUAL(1, Line.index);
}

void test_moveRight_given_happy_and_move_right_1_time(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  moveRight(&Line);
  moveRight(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(2, Line.index);
}

void test_moveRight_given_happy_and_move_right_5_time(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  moveRight(&Line);
  moveRight(&Line);
  moveRight(&Line);
  moveRight(&Line);
  moveRight(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(5, Line.index);
}

void test_moveRight_given_happy_and_move_right_6_time(void)
{
  char *buffer = "happy";
  line Line = {(void *)buffer, 0, 0};

  moveRight(&Line);
  moveRight(&Line);
  moveRight(&Line);
  moveRight(&Line);
  moveRight(&Line);
  moveRight(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(5, Line.index);
}

void test_printTillIndex_given_happy_should_print_happy(void)
{
  char buffer[] = "happy";

  printBufferTill(buffer,5);
}
