#include "unity.h"
#include "execute.h"
#include "seperate_func.h"
#include "stdio.h"
#include <stdlib.h>
#include "stdint.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parseAndCompare_with_exctact_same_valueexpect_pass(void)
{
    char* test = "Spi ";
    char* line = test;

    int a =parseAndCompare(&test,"Spi");
    TEST_ASSERT_TRUE(a);
    TEST_ASSERT_EQUAL_PTR(line+3,test);

}

void test_parseAndCompare_with_blank_space_infront_expect_pass(void)
{
  char* test = "      Spi ";
  char* line = test;

  int a =parseAndCompare(&test,"Spi");
  TEST_ASSERT_TRUE(a);
  TEST_ASSERT_EQUAL_PTR(line+9,test);
}

void test_parseAndCompare_with_wrongValue_expect_false(void)
{

  char* test = "Spq ";
  char* line = test;

  int a =parseAndCompare(&test,"Spi");
  TEST_ASSERT_FALSE(a);
  TEST_ASSERT_EQUAL_PTR(line,test);

}

void test_parseAndCompare_with_longerValue_expect_false(void)
{
  char* test = "Spi2 ";
  char* line = test;

  int a =parseAndCompare(&test,"Spi");
  TEST_ASSERT_FALSE(a);
  TEST_ASSERT_EQUAL_PTR(line,test);
}

void test_parseAndConvert(void)
{
  char* number = "123 ";

  int a = parseAndConvertNum(&number);
  printf("%i\n",a);
  TEST_ASSERT_EQUAL(a,123);
}

void test_parseAndConvert_with_blank_infront(void)
{
  char* number = "     456 ";

  int a = parseAndConvertNum(&number);
  printf("%i\n",a);
  TEST_ASSERT_EQUAL(a,456);
}

void test_parseAndConvert_with_char_between_the_word_expect_return_0(void)
{
  char* number = "2a7 ";

  int a = parseAndConvertNum(&number);
  printf("%i\n",a);
  TEST_ASSERT_EQUAL(a,0);
}

void test_parseAndConvert_with_char_expect_return_0(void)
{
  char* number = "abc ";

  int a = parseAndConvertNum(&number);
  printf("%i\n",a);
  TEST_ASSERT_EQUAL(a,0);
}

void test_parseAndInsertValue(void)
{
  char* test = "Mode = Low ";
  Mapping Spi1TableMapping[] = {
  {"Mode",&spi1Config.Mode,0},
  {"Direction",&spi1Config.Direction,0},
  {NULL,NULL,0},
  };
  parseAndInsertValue(&test,Spi1TableMapping);
  TEST_ASSERT_EQUAL(spi1Config.Mode,0);

}

void test_parseAndCompareTable_put_in_value_to_direction(void)
{
  char* test = "Direction = Low \n";
  Mapping Spi1TableMapping[] = {
  {"Mode",&spi1Config.Mode,0},
  {"Direction",&spi1Config.Direction,0},
  {NULL,NULL,0},
  };
  parseAndInsertValue(&test,Spi1TableMapping);
  TEST_ASSERT_EQUAL(spi1Config.Direction,0);

}

void test_parseAndReturnMappingTable(void)
{
  char* try= "Spi1Config Mode = 1 ";
  char* line = try;
  Mapping *map;
  map=parseAndReturnMappingTable(&try);
  printf("%s\n",map[1].name);
  TEST_ASSERT_EQUAL_STRING(map[0].name,"Mode");
  TEST_ASSERT_EQUAL_STRING(map[1].name,"Direction");
  TEST_ASSERT_EQUAL_PTR(line+10,try);
}

void test_parseAndCompareTable(void)
{
  char* try= "Spi1Config Mode = High Direction = High \n";
  parseAndCompareTable(&try);
  TEST_ASSERT_EQUAL(spi1Config.Mode,1);
  TEST_ASSERT_EQUAL(spi1Config.Direction,1);
}

void test_parseAndCompareTable_with_many_empty_space(void)
{
  char* try= "Spi1Config Mode     =       1                Direction    =     2        \n";
  parseAndCompareTable(&try);
  TEST_ASSERT_EQUAL(spi1Config.Mode,1);
  TEST_ASSERT_EQUAL(spi1Config.Direction,2);
}

void test_parseAndCompareTable_for_Spi2(void)
{
  char* try= "Spi2Config Mode = High Direction = High \n";
  parseAndCompareTable(&try);
  TEST_ASSERT_EQUAL(spi2Config.Mode,1);
  TEST_ASSERT_EQUAL(spi2Config.Direction,1);
}

void test_parseWord(void)
{
  char* test="hello world";
  char* ans;

  ans = parseWord(&test);
  printf("%s\n",ans);
  TEST_ASSERT_EQUAL_STRING("hello",ans);
  memset(wrong,0,10);
}

void test_Cexception(void)
{
  CEXCEPTION_T ex;
  char* test = "Spi2Config po \n";

  Try{
    parseAndCompareTable(&test);
    TEST_ASSERT_EQUAL(NOT_IN_TABLE,ex->errorCode);
  }Catch(ex){
    dumpException(ex);

  }
  free(ex);
}

void test_other_mapping_table_expect_error(void)
{
  CEXCEPTION_T ex;
  char* test = "Spi3Config lol = 0";

  Try{
    parseAndCompareTable(&test);
    TEST_ASSERT_EQUAL(NO_TABLE,ex->errorCode);

  }Catch(ex){
    dumpException(ex);

  }
  free(ex);
}

void test_WordMap(void)
{
  int ans;
  char * test = "Low ";

  ans = getValue(&test);

  TEST_ASSERT_EQUAL(0,ans);
}

void test_WordMap_error(void)
{
  CEXCEPTION_T ex;
  int ans;
  char* test = "fast ";

  Try{
  //  memset(wrong,0,10);
    ans = getValue(&test);
    TEST_ASSERT_EQUAL(NOT_IN_WORDMAP,ex->errorCode);
  }Catch(ex){
    dumpException(ex);

  }
  free(ex);
}
