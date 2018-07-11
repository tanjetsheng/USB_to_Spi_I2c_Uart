#ifndef _EXECUTE_H
#define _EXECUTE_H
#include "seperate_func.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Spi Spi;
struct Spi{
  int Instance ;
  int Mode ;
  int Direction;
  int DataSize ;
  int CLKPolarity ;
  int CLKPhase ;
  int NSS;
  int BaudRatePrescaler;
  int FirstBit;
  int TIMode ;
  int CRCCalculation;
  int CRCPolynomial ;
};

typedef struct Mapping Mapping;
struct Mapping{
char *name;
int* value;
int done;
};


Spi spi1Config;
Spi spi2Config;


Mapping* parseAndReturnMappingTable(char** cmd);
int parseAndCompare(char** cmd,char* string);
int parseAndConvertNum(char** cmd);
void parseAndInsertValue(char** cmd, Mapping* table);
void parseAndCompareTable(char** cmd);
#endif // _EXECUTE_H
