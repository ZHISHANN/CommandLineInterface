#include "unity.h"
#include "CLI.h"
#include "LinkedList.h"
#include "UserDefined.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "KeyAndConsole.h"

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

/*void xtest_processLine_given_cool_expect_cool_inside_linked_list(void)
{
  Line input = {"cool"};
  processLine(&input);

  TEST_ASSERT_EQUAL_STRING("cool",input.buffer);
}*/

//backspace for 1 time
//before               after
//"happy"              "happ"
void test_processBackspace_given_happy_and_backspace_1_time_expect_happ(void)
{
  Line line = {"happy", 5, 5};

  processBackspace(&line);

  printf("buffer : %s", line.buffer);
  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(4, line.index);
}

void test_processBackspace_given_happy_and_backspace_2_time_expect_hap(void)
{
  Line line = {"happy", 5, 5};

  processBackspace(&line);
  processBackspace(&line);

  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(3, line.index);
}

void test_processBackspace_given_dam_and_backspace_4_time_expect_empty(void)
{
  Line line = {"dam", 3, 3};

  processBackspace(&line);
  processBackspace(&line);
  processBackspace(&line);
  processBackspace(&line);

  TEST_ASSERT_EQUAL(3, line.last_index);
  TEST_ASSERT_EQUAL(0, line.index);
}

void test_moveLeft_given_happy_and_move_left_1_time(void)
{
  Line line = {{'h','e','l','l','o'}, 5};

  moveLeft(&line);

  //TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(4, line.index);
}

void test_moveLeft_given_happy_and_move_left_5_time(void)
{
  Line line = {{'s','m','i','l','e'}, 5};

  moveLeft(&line);
  moveLeft(&line);
  moveLeft(&line);
  moveLeft(&line);
  moveLeft(&line);

  //TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(0, line.index);
}

void test_moveLeft_given_happy_and_move_left_6_time(void)
{
  Line line = {{'h','a','p','p','y'},5};

  moveLeft(&line);
  moveLeft(&line);
  moveLeft(&line);
  moveLeft(&line);
  moveLeft(&line);
  moveLeft(&line);

  //TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(0, line.index);
}

void test_moveRight_given_happy_and_move_right_1_time(void)
{
  Line line = {"happy", 0, 0};

  moveRight(&line);
  moveRight(&line);

  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(2, line.index);
}

void test_moveRight_given_happy_and_move_right_5_time(void)
{
  Line line = {"happy", 0, 0};

  moveRight(&line);
  moveRight(&line);
  moveRight(&line);
  moveRight(&line);
  moveRight(&line);

  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(5, line.index);
}

void test_moveRight_given_happy_and_move_right_6_time(void)
{
  Line line = {"happy", 0, 0};

  moveRight(&line);
  moveRight(&line);
  moveRight(&line);
  moveRight(&line);
  moveRight(&line);
  moveRight(&line);

  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(5, line.index);
}

void test_printTillIndex_given_happy_should_print_happy(void)
{
  char buffer[] = "happy";

  printBufferTill(buffer,5);
}

void test_writeToBuffer_given_empty_list_expect_happy_write_to_buffer(void)
{
  Line line = {'\0',0,0};

  writeToBuffer(&line, 's');
  writeToBuffer(&line, 'm');
  writeToBuffer(&line, 'i');
  writeToBuffer(&line, 'l');
  writeToBuffer(&line, 'e');

  //printf("buffer : %s\n",Line.buffer);
  //printf("index : %d\n",Line.index);
  //printf("last index : %s",Line.last_index);
  TEST_ASSERT_EQUAL_STRING("smile",line.buffer);
  TEST_ASSERT_EQUAL(0,line.buffer[line.index]);
  TEST_ASSERT_EQUAL(5,line.index);
  TEST_ASSERT_EQUAL(5,line.last_index);
}

void test_writeToBuffer_given_hello_and_smile_in_line_expect_smile_write_into_buffer(void)
{
  Line line = {{'h','e','l','l','o'},5,6};

  writeToBuffer(&line, 's');
  writeToBuffer(&line, 'm');
  writeToBuffer(&line, 'i');
  writeToBuffer(&line, 'l');
  writeToBuffer(&line, 'e');

  printf("buffer : %s\n",line.buffer);

  TEST_ASSERT_EQUAL_STRING("hellosmile", line.buffer);
  TEST_ASSERT_EQUAL(0, line.buffer[line.index]);
  TEST_ASSERT_EQUAL(10, line.index);
  TEST_ASSERT_EQUAL(10,line.last_index);
}

void test_clearBuffer_given_happy_expect_happy_clear_in_buffer(void)
{
  Line line = {{'h','e','l','l','o'},5};

  printf("before clear buffer : %s\n",line.buffer);
  clearBuffer(&line);
  printf("after clear buffer : %s",line.buffer);
  TEST_ASSERT_EQUAL(0,line.index);
  TEST_ASSERT_EQUAL(0, line.buffer[line.index]);
  TEST_ASSERT_EQUAL(5,line.last_index);
}

void test_displayContent(void)
{
  Line line = {{'\0'},0,0};

  writeToBuffer(&line, 's');
  displayContent(&line);
}

void test_processLine(void)
{
  LinkedList history;
  Line line;
  strcpy(line.buffer, "hello");
  line.index = 5;
  LinkedListInit(&history);
  processLine(&history, &line);
  //printf("history data : %s",history.head->data);
  TEST_ASSERT_EQUAL_STRING(line.buffer, history.head->data);
}

void test_processLine_given_2_line_expect_both_insert_to_linkedlist(void)
{
  LinkedList history;
  Line line1, line2;
  strcpy(line1.buffer, "hello");
  line1.index = 5;
  strcpy(line2.buffer, "world");
  line2.index = 5;
  LinkedListInit(&history);
  processLine(&history, &line1);
  processLine(&history, &line2);
  //printf("history data : %s\n",history.head->data);
  //printf("history data : %s",history.head->next->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.head->next->data);
}

void test_processLine_given_3_line_expect_3_line_insert_to_linkedlist(void)
{
  LinkedList history;
  Line line1, line2,line3;
  strcpy(line1.buffer, "hello");
  line1.index = 5;
  strcpy(line2.buffer, "world");
  line2.index = 5;
  strcpy(line3.buffer, "haha");
  line3.index = 4;
  LinkedListInit(&history);
  processLine(&history, &line1);
  processLine(&history, &line2);
  processLine(&history, &line3);
  //printf("history data1 : %s\n",history.head->data);
  //printf("history data2 : %s\n",history.head->next->data);
  //printf("history data3 : %s",history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.tail->data);
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
