#include "unity.h"
#include "CLI.h"
#include "KeyAndConsole.h"
#include <stdio.h>
#include <stdint.h>
#include <conio.h>

void setUp(void){}

void tearDown(void){}

void test_Release(void)
{
  line Line = {NULL,0,0};
  uint8_t c = '\n';
  c = getch();

  if (c == 13)
    writeToBuffer(&Line,c);

  TEST_ASSERT_EQUAL('\n',Line.buffer);
}
