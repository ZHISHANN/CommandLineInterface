#include "unity.h"
#include "KeyAndConsole.h"
#include "LinkedList.h"
#include "CLI.h"

void setUp(void){}

void tearDown(void){}

void test_getKeyPressed(void)
{
  getKeyPressed();
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
  Line line = {"h",0,1};

  int rtn = isLineEmpty(&line);

  TEST_ASSERT_EQUAL(0,rtn);
}
