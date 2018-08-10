#include "unity.h"
#include "CLI.h"
#include "LinkedList.h"
#include "UserDefined.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

void setUp(void){}

void tearDown(void){}

/*void test_processKeyPress_given_item1_expect_string_copied(void)
{
  //int *addr;
  char *buffer = "hello";
  //LinkedList list = {NULL, NULL, 0};
  char *string = processKeyPress(buffer);

  TEST_ASSERT_EQUAL_STRING("hello",string);

  //ListItem item = {(void *)string, NULL};
  //line Line = {string,0,0};
  //addr = LinkedListAddToTail(&list,&item);
  //indexOfString(&Line);

  //TEST_ASSERT_EQUAL(5, Line.index);
  //TEST_ASSERT_EQUAL(6, Line.last_index);
  //TEST_ASSERT_EQUAL(addr, list.head);
  //TEST_ASSERT_EQUAL(addr, list.tail);
  //TEST_ASSERT_EQUAL(NULL, item.next);
}*/

void test_processLine_given_cool_expect_cool_inside_linked_list(void)
{
  line input = {"cool"};
  processLine(&input);

  TEST_ASSERT_EQUAL_STRING("cool",input.buffer);
}

//backspace for 1 time
//before               after
//"happy"              "happ"
void test_processBackspace_given_happy_and_backspace_1_time_expect_happ(void)
{
  line Line = {"happy", 0, 0};

  processBackspace(&Line);

  printf("buffer : %s", Line.buffer);
  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(4, Line.index);
}

void test_processBackspace_given_happy_and_backspace_2_time_expect_hap(void)
{
  line Line = {"happy", 0, 0};

  processBackspace(&Line);
  processBackspace(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(3, Line.index);
}

void test_processBackspace_given_happy_and_backspace_3_time_expect_ha(void)
{
  line Line = {"dam", 0, 0};

  processBackspace(&Line);
  processBackspace(&Line);
  processBackspace(&Line);
  processBackspace(&Line);

  TEST_ASSERT_EQUAL(3, Line.last_index);
  TEST_ASSERT_EQUAL(0, Line.index);
}

void test_moveLeft_given_happy_and_move_left_1_time(void)
{
  line Line = {"happy", 0, 0};

  moveLeft(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(4, Line.index);
}

void test_moveLeft_given_happy_and_move_left_5_time(void)
{
  line Line = {"happy", 0, 0};

  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(0, Line.index);
}

void test_moveLeft_given_happy_and_move_left_6_time(void)
{
  line Line = {"happy", 0, 0};

  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);
  moveLeft(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(0, Line.index);
}

void test_moveLeft_given_h_and_move_left_1_time(void)
{
  line Line = {"h", 0, 0};

  moveLeft(&Line);

  TEST_ASSERT_EQUAL(1, Line.last_index);
  TEST_ASSERT_EQUAL(0, Line.index);
}

void test_moveRight_given_happy_and_move_right_1_time(void)
{
  line Line = {"happy", 0, 0};

  moveRight(&Line);
  moveRight(&Line);

  TEST_ASSERT_EQUAL(5, Line.last_index);
  TEST_ASSERT_EQUAL(2, Line.index);
}

void test_moveRight_given_happy_and_move_right_5_time(void)
{
  line Line = {"happy", 0, 0};

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
  line Line = {"happy", 0, 0};

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

void test_writeToBuffer_given_empty_list_expect_happy_write_to_buffer(void)
{
  line Line = {'\0',0,0};

  writeToBuffer(&Line, 's');
  writeToBuffer(&Line, 'm');
  writeToBuffer(&Line, 'i');
  writeToBuffer(&Line, 'l');
  writeToBuffer(&Line, 'e');

  //printf("buffer : %s\n",Line.buffer);
  //printf("index : %d\n",Line.index);
  TEST_ASSERT_EQUAL_STRING("smile",Line.buffer);
  //printf("last index : %s",Line.last_index);
  TEST_ASSERT_NULL(Line.buffer[Line.last_index]);
  TEST_ASSERT_EQUAL(6,Line.last_index);
  TEST_ASSERT_EQUAL(5,Line.index);
}

void test_writeToBuffer_given_hello_and_smile_in_line_expect_smile_write_into_buffer(void)
{
  line Line = {"hello",5,6};

  writeToBuffer(&Line, 's');
  writeToBuffer(&Line, 'm');
  writeToBuffer(&Line, 'i');
  writeToBuffer(&Line, 'l');
  writeToBuffer(&Line, 'e');

  printf("buffer : %s\n",Line.buffer);

  TEST_ASSERT_EQUAL_STRING("hellosmile", Line.buffer);
  TEST_ASSERT_NULL(Line.buffer[Line.last_index]);
  TEST_ASSERT_EQUAL(11, Line.last_index);
  TEST_ASSERT_EQUAL(10, Line.index);
}

void test_clearBuffer_given_happy_expect_happy_clear_in_buffer(void)
{
  line Line = {"happy",5,6};

  clearBuffer(&Line);
  printf("buffer : %s",Line.buffer);
  TEST_ASSERT_EQUAL(0,Line.index);
  TEST_ASSERT_NULL(Line.buffer[0]);
}

/*void test_clearConsoleLine_given_happy_expect_happy_clear_in_console_line(void)
{
  line Line = {"happy",5,6};

  clearConsoleLine(&Line, Line.index);

  TEST_ASSERT_EQUAL(0,Line.index);
}

void test_clearConsoleLine_given_NULL_expect_clear_in_console_line(void)
{
  line Line = {'\0',0,0};

  clearConsoleLine(&Line, Line.last_index);

  TEST_ASSERT_EQUAL(0,Line.index);
}*/
