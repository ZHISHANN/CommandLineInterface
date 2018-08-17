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

void xtest_LinkedListAddToTail_given_third_item_expect_inserted(void)
{
  char *str;
  Line line1 = {"Hello", 5, 0};
  Line line2 = {"Hi", 2, 0};
  Line line3 = {"Dummy", 5, 0};
  ListItem item3 = {"Dummy"};
  ListItem item2 = {"Hi"};
  ListItem item1 = {"Hello"};
  LinkedList list = {NULL, NULL, 0};

  LinkedListAddToTail(&list, &item1);
  LinkedListAddToTail(&list, &item2);
  str = recallPrevious(&list);

  TEST_ASSERT_NOT_NULL(str);
  TEST_ASSERT_EQUAL_STRING("Hi", str);

  LinkedListAddToTail(&list, &item3);

  TEST_ASSERT_EQUAL_STRING(line3.buffer, list.tail->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, list.tail->next->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, list.tail->prev->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, list.tail->prev->prev->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, list.head->prev->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, list.head->next->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, list.head->next->next->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, list.head->data);
  TEST_ASSERT_EQUAL(3, list.count);
}

void test_processLine_given_1_data_expect_inserted(void)
{
  LinkedList history;
  Line line = {"hello", 5, 0};

  LinkedListInit(&history);
  processLine(&history, &line);

  TEST_ASSERT_EQUAL_STRING("hello", history.head->data);
  TEST_ASSERT_EQUAL_STRING("hello", history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line.buffer, history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line.buffer, history.head->data);
  TEST_ASSERT_EQUAL_STRING(line.buffer, history.head->next->data);
  TEST_ASSERT_EQUAL_STRING(line.buffer, history.head->prev->data);
  TEST_ASSERT_EQUAL_STRING(line.buffer, history.tail->next->data);
  TEST_ASSERT_EQUAL_STRING(line.buffer, history.tail->prev->data);
  TEST_ASSERT_EQUAL(1, history.count);
}

void test_processLine_given_2_line_expect_both_insert_to_linkedlist(void)
{
  LinkedList history;
  Line line1 = {"hello", 5, 0};
  Line line2 = {"world", 5, 0};

  LinkedListInit(&history);
  processLine(&history, &line1);
  processLine(&history, &line2);

  TEST_ASSERT_EQUAL_STRING("hello", history.head->data);
  TEST_ASSERT_EQUAL_STRING("world", history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.head->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.head->next->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.head->prev->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.tail->next->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.tail->prev->data);
  TEST_ASSERT_EQUAL(2, history.count);
}

void test_processLine_given_3_line_expect_3_line_insert_to_linkedlist(void)
{
  LinkedList history;
  Line line1 = {"hello", 5, 0};
  Line line2 = {"world", 5, 0};
  Line line3 = {"haha", 4, 0};

  LinkedListInit(&history);
  processLine(&history, &line1);
  processLine(&history, &line2);
  processLine(&history, &line3);
  //temp = list->head;
  //(char *)(temp->data) = line1.buffer;
  //temp = temp->next;

  TEST_ASSERT_EQUAL_STRING("hello", history.head->data);
  TEST_ASSERT_EQUAL_STRING("haha", history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.head->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.head->next->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.head->next->next->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.head->prev->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.tail->next->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.tail->prev->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.tail->prev->prev->data);
  TEST_ASSERT_EQUAL(3, history.count);
}

void test_processLine_given_4_line_expect_the_first_list_deleted(void)
{
  LinkedList history;
  Line line1 = {"hello", 5, 0};
  Line line2 = {"world", 5, 0};
  Line line3 = {"haha", 4, 0};
  Line line4 = {"smile", 5, 0};

  LinkedListInit(&history);
  processLine(&history, &line1);
  processLine(&history, &line2);
  processLine(&history, &line3);
  processLine(&history, &line4);

  TEST_ASSERT_EQUAL_STRING("world", history.head->data);
  TEST_ASSERT_EQUAL_STRING("smile", history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.head->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.head->next->data);
  TEST_ASSERT_EQUAL_STRING(line4.buffer, history.head->next->next->data);
  TEST_ASSERT_EQUAL_STRING(line4.buffer, history.head->prev->data);
  TEST_ASSERT_EQUAL_STRING(line4.buffer, history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.tail->next->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.tail->prev->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.tail->prev->prev->data);
  TEST_ASSERT_EQUAL(3, history.count);
}

//backspace for 1 time
//before               after
//"happy"              "happ"
void test_processBackspace_given_happy_and_backspace_1_time_expect_happ(void)
{
  Line line = {"happy", 5, 5};

  processBackspace(&line);

  //printf("buffer : %s", line.buffer);
  TEST_ASSERT_EQUAL_STRING("happ", line.buffer);
  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(4, line.index);
}

void test_processBackspace_given_happy_and_backspace_2_time_expect_hap(void)
{
  Line line = {"happy", 5, 5};

  processBackspace(&line);
  processBackspace(&line);

  TEST_ASSERT_EQUAL_STRING("hap", line.buffer);
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

  TEST_ASSERT_EQUAL_STRING("", line.buffer);
  TEST_ASSERT_EQUAL(3, line.last_index);
  TEST_ASSERT_EQUAL(0, line.index);
}

void test_moveLeft_given_happy_and_move_left_1_time(void)
{
  Line line = {{'h','e','l','l','o'}, 5};

  moveLeft(&line);

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

  //printf("buffer : %s\n",line.buffer);

  TEST_ASSERT_EQUAL_STRING("hellosmile", line.buffer);
  TEST_ASSERT_EQUAL(0, line.buffer[line.index]);
  TEST_ASSERT_EQUAL(10, line.index);
  TEST_ASSERT_EQUAL(10,line.last_index);
}

void test_clearBuffer_given_happy_expect_happy_clear_in_buffer(void)
{
  Line line = {{'h','e','l','l','o'},5};

  //printf("before clear buffer : %s\n",line.buffer);
  clearBuffer(&line);
  //printf("after clear buffer : %s",line.buffer);
  TEST_ASSERT_EQUAL(0,line.index);
  TEST_ASSERT_EQUAL(0, line.buffer[line.index]);
  TEST_ASSERT_EQUAL(5,line.last_index);
}

void test_copyStringToLine_given_space_and_insert_new_data_expect_data_inserted(void)
{
  Line line = {"       ", '\0', '\0'};
  copyStringToLine(&line, "smile");

  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
  TEST_ASSERT_EQUAL_STRING("smile", line.buffer);
  TEST_ASSERT_EQUAL(5, line.index);
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
}

void test_printTillIndex_given_happy_should_print_happy(void)
{
  char buffer[] = "happy";

  printBufferTill(buffer,5);
}*/
