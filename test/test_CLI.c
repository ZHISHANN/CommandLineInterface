#include "unity.h"
#include "CLI.h"
#include "LinkedList.h"
#include "UserDefined.h"
#include "KeyAndConsole.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

void setUp(void){}

void tearDown(void){}

void test_given_happy_eat_hahahahahaha_then_move_left_2_time_and_recallPrevious_2_time_expect_return_eat(void)
{
  LinkedList history;
  Line line1 = {"happy", 5, 5};
  Line line2 = {"eat", 3, 3};
  Line line3 = {"hahahahahaha", 12, 12};
  Line line = {{'\0'}, 0, 0};

  linkedListInit(&history);
  processLine(&history, &line1);
  processLine(&history, &line2);
  processLine(&history, &line3);

  TEST_ASSERT_EQUAL_STRING("happy", history.head->data);
  TEST_ASSERT_EQUAL_STRING("hahahahahaha", history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.head->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.head->next->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.head->next->next->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.head->prev->data);
  TEST_ASSERT_EQUAL_STRING(line3.buffer, history.tail->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.tail->next->data);
  TEST_ASSERT_EQUAL_STRING(line2.buffer, history.tail->prev->data);
  TEST_ASSERT_EQUAL_STRING(line1.buffer, history.tail->prev->prev->data);
  TEST_ASSERT_EQUAL(3, history.count);

  moveLeft(&line3);
  moveLeft(&line3);

  TEST_ASSERT_EQUAL(10, line3.index);

  TEST_ASSERT_EQUAL_STRING(line3.buffer, recallPrevious(&history));
  TEST_ASSERT_EQUAL_STRING(line2.buffer, recallPrevious(&history));
}

void test_linkedListAddToTail_given_third_item_expect_inserted(void)
{
  char *str;
  Line line1 = {"Hello", 5, 0};
  Line line2 = {"Hi", 2, 0};
  Line line3 = {"Dummy", 5, 0};
  ListItem item3 = {"Dummy"};
  ListItem item2 = {"Hi"};
  ListItem item1 = {"Hello"};
  LinkedList list = {NULL, NULL, 0};
  resetRecalledItem(&list);

  linkedListAddToTail(&list, &item1);
  linkedListAddToTail(&list, &item2);
  str = recallPrevious(&list);

  TEST_ASSERT_NOT_NULL(str);
  TEST_ASSERT_EQUAL_STRING("Hi", str);

  linkedListAddToTail(&list, &item3);

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

  linkedListInit(&history);
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

  linkedListInit(&history);
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

  linkedListInit(&history);
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

  linkedListInit(&history);
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

void test_processLine_given_4_line_seperately_expect_the_first_list_deleted(void)
{
  LinkedList history;
  Line line1 = {"hello", 5, 0};
  Line line2 = {"world", 5, 0};
  Line line3 = {"haha", 4, 0};
  Line line4 = {"smile", 5, 0};

  linkedListInit(&history);
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

  processLine(&history, &line3);

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

  TEST_ASSERT_EQUAL_STRING("happ", line.buffer);
  TEST_ASSERT_EQUAL(4, line.index);
}

void test_processBackspace_given_happy_and_backspace_2_time_expect_hap(void)
{
  Line line = {"happy", 5, 5};

  processBackspace(&line);
  processBackspace(&line);

  TEST_ASSERT_EQUAL_STRING("hap", line.buffer);
  TEST_ASSERT_EQUAL(3, line.index);
}

void test_processBackspace_given_dam_and_backspace_4_time_expect_empty(void)
{
  Line line = {"dam",3,3};

  processBackspace(&line);
  processBackspace(&line);
  processBackspace(&line);
  processBackspace(&line);

  TEST_ASSERT_EQUAL_STRING("", line.buffer);
  TEST_ASSERT_EQUAL(0, line.index);
}

void test_processBackspace_given_m_and_backspace_1_time_expect_empty(void)
{
  Line line = {"m",1,1};

  processBackspace(&line);

  TEST_ASSERT_EQUAL_STRING("", line.buffer);
  TEST_ASSERT_EQUAL(0, line.index);
}

void test_processBackspace_given_empty_line(void)
{
  Line line = {{'\0'},0,0};

  processBackspace(&line);
  processBackspace(&line);

  TEST_ASSERT_EQUAL_STRING("", line.buffer);
  TEST_ASSERT_EQUAL(0, line.index);
}

void test_processBackspace_given_abcd_moveLeft_twice_then_backspace_once_expect_return_acd(void)
{
  Line line = {"abcd",4,4};

    moveLeft(&line);
    moveLeft(&line);
    processBackspace(&line);

    TEST_ASSERT_EQUAL_STRING("acd", line.buffer);
    TEST_ASSERT_EQUAL(1, line.index);
}

void test_processBackspace_given_abcd_moveLeft_twice_then_tab_and_backspace_once_expect_return_ab___cd(void)
{
  Line line = {"abcd",4,4};

  moveLeft(&line);
  moveLeft(&line);
  insertTab(&line);
  processBackspace(&line);

  TEST_ASSERT_EQUAL_STRING("ab   cd", line.buffer);
  TEST_ASSERT_EQUAL(5, line.index);
}

void test_moveLeft_given_empty_line(void)
{
  Line line = {{'\0'},0,0};

  moveLeft(&line);
  moveLeft(&line);

  TEST_ASSERT_EQUAL(0, line.index);
}

void test_moveLeft_given_me_then_moveLeft_1_time_expect_index_equal_1(void)
{
  Line line = {"me" ,2};

  moveLeft(&line);

  TEST_ASSERT_EQUAL(1, line.index);
}

void test_moveLeft_given_happy_and_move_left_1_time(void)
{
  Line line = {{'h','e','l','l','o'}, 5};

  moveLeft(&line);

  TEST_ASSERT_EQUAL(4, line.index);
  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
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
  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
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
  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
}

void test_moveRight_and_moveLeft_given_me_then_move_left_2_time_move_right_1_time_expect_index_equal_1(void)
{
  Line line = {"me", 2};

  moveLeft(&line);
  moveLeft(&line);
  moveRight(&line);

  TEST_ASSERT_EQUAL(1, line.index);
}

void test_moveRight_given_empty_line(void)
{
  Line line = {{'\0'},0,0};

  moveRight(&line);
  moveRight(&line);

  TEST_ASSERT_EQUAL(0, line.index);
}

void test_moveRight_given_happy_and_move_right_1_time(void)
{
  Line line = {"happy", 0, 0};

  moveRight(&line);
  moveRight(&line);

  TEST_ASSERT_EQUAL(5, line.last_index);
  TEST_ASSERT_EQUAL(2, line.index);
  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
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
  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
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
  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
}

void test_writeToBuffer_given_empty_list_expect_happy_write_to_buffer(void)
{
  Line line = {'\0',0,0};

  writeToBuffer(&line, 's');
  writeToBuffer(&line, 'm');
  writeToBuffer(&line, 'i');
  writeToBuffer(&line, 'l');
  writeToBuffer(&line, 'e');

  TEST_ASSERT_EQUAL_STRING("smile",line.buffer);
  TEST_ASSERT_EQUAL('\0',line.buffer[5]);
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

  TEST_ASSERT_EQUAL_STRING("hellosmile", line.buffer);
  TEST_ASSERT_EQUAL('\0', line.buffer[10]);
  TEST_ASSERT_EQUAL(10, line.index);
  TEST_ASSERT_EQUAL(10,line.last_index);
}

void test_writeToBuffer_given_smile_and_insert_NULL_expect_smile_in_buffer(void)
{
  Line line = {"smile",5,5};

  writeToBuffer(&line,'\0');

  TEST_ASSERT_EQUAL_STRING("smile", line.buffer);
  TEST_ASSERT_EQUAL('\0',line.buffer[5]);
  TEST_ASSERT_EQUAL(5,line.index);
  TEST_ASSERT_EQUAL(5,line.last_index);
}

void test_writeToBuffer_given_abcd_moveLeft_twice_replace_c_with_a_expect_return_abac(void)
{
  Line line = {"abcd",4,4};

  moveLeft(&line);
  moveLeft(&line);
  writeToBuffer(&line,'a');

  TEST_ASSERT_EQUAL_STRING("abad", line.buffer);
}

void test_writeToBuffer_given_abcd_then_clearBuffer_and_add_mama_expect_return_mama(void)
{
  Line line = {"abcd",4,4};

  clearBuffer(&line);
  writeToBuffer(&line,'m');
  writeToBuffer(&line,'a');
  writeToBuffer(&line,'m');
  writeToBuffer(&line,'a');

  TEST_ASSERT_EQUAL_STRING("mama", line.buffer);
}

void test_clearBuffer_given_empty_line(void)
{
  Line line = {{'\0'},0,0};

  clearBuffer(&line);
  TEST_ASSERT_EQUAL(0,line.index);
  TEST_ASSERT_EQUAL('\0', line.buffer[line.index]);
  TEST_ASSERT_EQUAL(0,line.last_index);
}

void test_clearBuffer_given_happy_expect_happy_clear_in_buffer(void)
{
  Line line = {{'h','e','l','l','o'},5};

  printf("before clear buffer : %s\n",line.buffer);
  clearBuffer(&line);
  printf("after clear buffer : %s",line.buffer);
  TEST_ASSERT_EQUAL(0,line.index);
  TEST_ASSERT_EQUAL('\0', line.buffer[line.index]);
  TEST_ASSERT_EQUAL(5,line.last_index);
}

void test_copyStringToLine_given_space_and_insert_new_data_expect_data_inserted(void)
{
  Line line = {"       ", 0, 0};
  copyStringToLine(&line, "smile");

  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
  TEST_ASSERT_EQUAL_STRING("smile", line.buffer);
  TEST_ASSERT_EQUAL(5, line.index);
}

void test_copyStringToLine_given_good_and_insert_empty_line_expect_good_display(void)
{
  Line line = {"good",4,4};
  copyStringToLine(&line,'\0');

  TEST_ASSERT_EQUAL_STRING("good", line.buffer);
  TEST_ASSERT_EQUAL(4, line.index);
}

void test_copyStringToLine_given_happy_and_together_data_expect_happy_display(void)
{
  Line line = {"       ", 0, 0};
  copyStringToLine(&line, "together");

  TEST_ASSERT_EQUAL('\0', line.buffer[8]);
  TEST_ASSERT_EQUAL_STRING("together", line.buffer);
  TEST_ASSERT_EQUAL(8, line.index);

  copyStringToLine(&line, "happy");

  TEST_ASSERT_EQUAL('\0', line.buffer[5]);
  TEST_ASSERT_EQUAL_STRING("happy", line.buffer);
  TEST_ASSERT_EQUAL(5, line.index);
}

void test_isLineEmpty_given_space_expect_return_1(void)
{
  Line line = {""};

  int rtn = isLineEmpty(&line);

  TEST_ASSERT_EQUAL(1,rtn);
}

void test_isLineEmpty_given_space_space_expect_return_1(void)
{
  Line line = {" "};

  int rtn = isLineEmpty(&line);

  TEST_ASSERT_EQUAL(1,rtn);
}

void test_isLineEmpty_given_tab_and_space_expect_return_1(void)
{
  Line line = {"   \t   "};

  int rtn = isLineEmpty(&line);

  TEST_ASSERT_EQUAL(1,rtn);
}

void test_isLineEmpty_given_value_expect_return_0(void)
{
  Line line = {"h",1,1};

  int rtn = isLineEmpty(&line);

  TEST_ASSERT_EQUAL(0,rtn);
}

void test_isLineEmpty_given_value_and_space_in_between_expect_return_0(void)
{
  Line line = {"   h    ",8,8};

  int rtn = isLineEmpty(&line);

  TEST_ASSERT_EQUAL(0,rtn);
}

void test_insertTab_given_sad_moveLeft_once_then_tab_once_expect_index_equal_7(void)
{
  Line line = {"sad",3,3};

  moveLeft(&line);
  TEST_ASSERT_EQUAL(2, line.index);
  //printf("before : %s\n",line.buffer);
  insertTab(&line);
  //printf("after : %s",line.buffer);
  TEST_ASSERT_EQUAL(6, line.index);
}

void test_insertTab_given_sad_then_tab_once_expect_index_equal_7(void)
{
  Line line = {"sad",3,3};

  TEST_ASSERT_EQUAL(3, line.index);
  //printf("before : %s\n",line.buffer);
  insertTab(&line);
  //printf("after : %s",line.buffer);
  TEST_ASSERT_EQUAL(7, line.index);
}

void test_insertTab_given_wanna_moveLeft_twice_then_tab_twice_expect_index_equal_11(void)
{
  Line line = {"wanna",5,5};

  moveLeft(&line);
  moveLeft(&line);
  TEST_ASSERT_EQUAL(3, line.index);
  //printf("before : %s\n",line.buffer);
  insertTab(&line);
  insertTab(&line);
  //printf("after : %s\n",line.buffer);
  TEST_ASSERT_EQUAL(11, line.index);
}

void test_insertKey_given_abde_moveLeft_twice_insert_c_expect_return_abcde(void)
{
  Line line = {"abde",4,4};

  moveLeft(&line);
  moveLeft(&line);
  insertKey(&line);
  writeToBuffer(&line,'c');

  TEST_ASSERT_EQUAL_STRING("abcde", line.buffer);
  TEST_ASSERT_EQUAL(3, line.index);
  TEST_ASSERT_EQUAL(5, line.last_index);
}

void test_insertKey_given_abc_insert_d_expect_return_abcd(void)
{
  Line line = {"abc",3,3};

  insertKey(&line);
  writeToBuffer(&line,'d');

  TEST_ASSERT_EQUAL_STRING("abcd", line.buffer);
  TEST_ASSERT_EQUAL(4, line.index);
  TEST_ASSERT_EQUAL(4, line.last_index);
}

void test_insertKey_given_abef_moveLeft_twice_insert_c_and_d_expect_return_abcdef(void)
{
  Line line = {'\0'};

  copyStringToLine(&line, "happy");
  //moveCursorToEnd(&line);
  //clearPreviousRecord();
  displayContent(&line);
  moveLeft(&line);
  //displayCursor(&line);
  insertKey(&line);
  writeToBuffer(&line,'d');
  displayContent(&line);
  clearBuffer(&line);
  //displayCursor(&line);
  copyStringToLine(&line, "hey");
  moveLeft(&line);
  insertKey(&line);
  writeToBuffer(&line,'d');
  displayContent(&line);
  //displayCursor(&line);
}
