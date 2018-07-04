#include "unity.h"
#include "seperate_func.h"
#include "stdio.h"
#include <stdlib.h>
#include "stdint.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_seperate_func_getting_value_get_spi(void)
{
  char* test = "spi mode=abc speed=high";
  char* ans;
//printf("%d\n",test);
  ans = extract(test);
      printf("%s\n",ans);
TEST_ASSERT_EQUAL_STRING(ans,"spi");

  }

void test_shifter(void)
{
  char* ans;
    char* test = "spi mode=abc speed=high";
    ans=shifter(test,4);
  printf("%s\n",ans);
  TEST_ASSERT_EQUAL_STRING(ans,"mode=abc speed=high");
}
