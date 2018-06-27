#include "unity.h"
#include "seperate_func.h"
#include "stdio.h"
#include <stdlib.h>
void setUp(void)
{
}

void tearDown(void)
{
}

void test_seperate_func_getting_value(void)
{
  char** ans;
  char *try= "x10 y2 z50 f100";
  ans=seperate(try);
printf("\nans = %s",ans[0]);

//int i;
//free(ans);
/* for(i=0;i < 10;i++)
    free(ans[i]);*/
}
