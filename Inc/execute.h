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

typedef struct SpiSend SpiSend;
struct SpiSend{
  int value[10];
};

void* funcptr;

typedef struct Maxmin Maxmin;
struct Maxmin{
  int max;
  int min;
};

typedef struct Mapping Mapping;
struct Mapping{
char *name;
int* value;
int done;
//void (*funcptr)(char** cmd,Mapping TableMapping);
Maxmin *maxmin;
};

typedef struct WordMap WordMap;
struct WordMap{
char *name;
int value;
};


SpiSend Send;
Spi spi1Config;
Spi spi2Config;
char wrong[10];

Mapping* parseAndReturnMappingTable(char** cmd);
int parseAndCompare(char** cmd,char* string);
int parseAndConvertNum(char** cmd);
void parseAndInsertValue(char** cmd, Mapping* table);
void parseAndCompareTable(char** cmd);
char* parseWord(char** cmd);
int getValue(char** cmd);
Mapping* initialDoneValue(Mapping* table);
void SpiSendValue(char** cmd);
#endif // _EXECUTE_H
