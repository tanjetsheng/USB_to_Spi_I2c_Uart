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

typedef struct I2cSend I2cSend;
struct I2c{
	int Instance;
	int ClockSpeed;
	int OwnAddress1;
	int AddressingMode;
	int DualAddressMode;
	int OwnAddress2;
	int GeneralCallMode;
	int NoStretchMode;
};

typedef struct I2cSend I2cSend;
struct I2cSend{
	uint8_t address;
	uint8_t value[10];
	int total;
};

typedef struct SpiSend SpiSend;
struct SpiSend{
  uint8_t value[10];
  int total;
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


I2cSend I2cV;

SpiSend Send;
Spi spi1Config;
Spi spi2Config;
char wrong[10];

Mapping* parseAndReturnMappingTable(char** cmd);
int parseAndCompare(char** cmd,char* string);
int parseAndConvertNum(char** cmd);
void parseAndInsertValue(char** cmd, Mapping* table);
char* parseAndCompareTable(char** cmd);
char* parseWord(char** cmd);
int getValue(char** cmd);
Mapping* initialDoneValue(Mapping* table);
void SpiSendValue(char** cmd);
void I2cMasterSendValue(char** cmd);
#endif // _EXECUTE_H
