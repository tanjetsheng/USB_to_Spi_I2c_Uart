#include "unity.h"
#include "execute.h"
#include "seperate_func.h"
#include "stdio.h"
#include <stdlib.h>
#include "stdint.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "CException.h"
#include "mock_mockFunc.h"


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
  WordMap WordMapping[] ={
    {"Low",0},
      {NULL,NULL,0},
  };
  Mapping Spi1TableMapping[] = {
  {"Mode",&spi1Config.Mode,0},
  {"Direction",&spi1Config.Direction,0},
  {NULL,NULL,0},
  };
  parseAndInsertValue(&test,Spi1TableMapping,WordMapping);
  TEST_ASSERT_EQUAL(spi1Config.Mode,0);

}

void test_parseAndCompareTable_put_in_value_to_direction(void)
{
  char* test = "Direction = Low \n";
  WordMap WordMapping[] ={
    {"Low",0},
      {NULL,NULL,0},
  };
  Mapping Spi1TableMapping[] = {
  {"Mode",&spi1Config.Mode,0},
  {"Direction",&spi1Config.Direction,0},
  {NULL,NULL,0},
  };
  parseAndInsertValue(&test,Spi1TableMapping,WordMapping);
  TEST_ASSERT_EQUAL(spi1Config.Direction,0);

}

void test_parseAndReturnMappingTable(void)
{
  char* try= "Spi1Config Mode = 1 ";
  char* line = try;
  Mapping *map;
  map=parseAndReturnMappingTable(&try);
  printf("%s\n",map[1].name);
//  printf("-------->%i\n",map[0].maxmin->min);
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
  char* try= "Spi1Config Mode     =       High                Direction    =     Low        \n";
  parseAndCompareTable(&try);
  TEST_ASSERT_EQUAL(spi1Config.Mode,1);
  TEST_ASSERT_EQUAL(spi1Config.Direction,0);
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
  uint8_t data= {0x4e};
//  uint8_t value ={0x0023};
  //*value = 0x0002;
   CDC_Transmit_FS_ExpectAndReturn(&data,35,0);

  Try{
    parseAndCompareTable(&test);
    TEST_ASSERT_EQUAL(NOT_IN_TABLE,ex->errorCode);
    memset(wrong,0,10);
  }Catch(ex){
    dumpException(ex);

  }
  free(ex);
}

void test_other_mapping_table_expect_error(void)
{
  CEXCEPTION_T ex;
  char* test = "Spi3Config lol = 0";
  uint8_t data= {0x44};
   CDC_Transmit_FS_ExpectAndReturn(&data,48,0);

  Try{
    parseAndCompareTable(&test);
    TEST_ASSERT_EQUAL(NO_TABLE,ex->errorCode);

  }Catch(ex){
    dumpException(ex);
    memset(wrong,0,10);
  }
  free(ex);
}

void test_WordMap(void)
{
  int ans;
  WordMap WordMapping[] ={
    {"Low",0},
      {NULL,NULL,0},
  };
  char * test = "Low ";

  ans = getValue(&test,WordMapping);

  TEST_ASSERT_EQUAL(0,ans);
}

void test_WordMap_error(void)
{
  CEXCEPTION_T ex;
  int ans;
  char* test = "fast ";
  WordMap WordMapping[] ={
    {"Low",0},
      {NULL,NULL,0},
  };
  uint8_t data= {0x4e};
   CDC_Transmit_FS_ExpectAndReturn(&data,35,0);
  Try{
  //  memset(wrong,0,10);
    ans = getValue(&test,WordMapping);
    TEST_ASSERT_EQUAL(NOT_IN_WORDMAP,ex->errorCode);
  }Catch(ex){
    dumpException(ex);
    memset(wrong,0,10);
  }
  free(ex);
}

void test_reconfigure(void)
{
  CEXCEPTION_T ex;
  char* try= "Spi2Config Mode = High Mode = High  \n";
  uint8_t data= {0x61};
   CDC_Transmit_FS_ExpectAndReturn(&data,38,0);

  Try{
    parseAndCompareTable(&try);
    TEST_ASSERT_EQUAL(CONFIGURED,ex->errorCode);
  }Catch(ex){
    dumpException(ex);
    memset(wrong,0,10);
  }
  free(ex);
}

void test_Spisend(void)
{
  char* send ="SpiWrite 23 45 65\n";
  parseAndCompareTable(&send);
  TEST_ASSERT_EQUAL(23, Send.value[0]);

}

 void test_hexToString(void)
{
  uint8_t* buffer[] ={0x17EF};
  char* trans;

  trans=malloc(10);

  trans=getHexString(trans,buffer,2);
  TEST_ASSERT_EQUAL_STRING(trans,"ef17 ");
  free(trans);
}

void test_getReturnI2c(void)
{
  char* test = "I2cConfig dutyCycle = 2dutycycle\n";
  char* output;
  output =parseAndCompareTable(&test);
  TEST_ASSERT_EQUAL_STRING("I2cConfig",output);
}
