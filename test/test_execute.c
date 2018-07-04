#include "unity.h"
#include "execute.h"
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

void test_execute_NeedToImplement(void)
{
    char* test = "SpiConfig mode=1 speed=high\n";
    //Spi ans;
    execute(test);
    //printf("%s\n",test);
  //  TEST_ASSERT_EQUAL(ans.Mode,1);
}

void test_error(void)
{
    char* test = "adkj sdfjnaksdf";
    execute(test);
}
