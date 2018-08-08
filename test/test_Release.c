#include "unity.h"
#include <stdio.h>
#include <stdint.h>
#include <conio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Release(void)
{

    printf("Hello\n");
    uint8_t ac, c = 'h';
    c = getch(); //button pressed

    if (c == 224 || c == 0)
      ac = getch();

    printf("%c (%d) has been pressed\n",c,c);
    if (c == 224 || c == 0)
      printf("%c (%d) the actual character pressed\n",ac ,ac);

}
