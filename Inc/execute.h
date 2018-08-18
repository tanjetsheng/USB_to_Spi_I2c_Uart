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

typedef struct I2c I2c;
struct I2c{
	int Instance;
  int DutyCycle;
	int ClockSpeed;
	int OwnAddress1;
	int AddressingMode;
	int DualAddressMode;
	int OwnAddress2;
	int GeneralCallMode;
	int NoStretchMode;
};

typedef struct  Usart Usart;
struct Usart{
  int WordLength;
  int StopBit;
  int Parity;
  int Mode;
  int ClkPolarity;
  int ClkPhase;
  int clkLastBit;
};
typedef struct I2cMemWrite I2cMemWrite;
struct I2cMemWrite{
	uint8_t MemAddr;
	uint8_t address;
	uint8_t value[10];
	int total;
};

typedef struct I2cMemRead I2cMemRead;
struct I2cMemRead{
	uint8_t MemAddr;
	uint8_t address;
	int total;
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

typedef struct UartSend UartSend;
struct UartSend{
	uint8_t value[10];
	int total;
};

void* funcptr;


typedef struct Mapping Mapping;
struct Mapping{
char *name;
int* value;
int done;
//void (*funcptr)(char** cmd,Mapping TableMapping);

};

typedef struct WordMap WordMap;
struct WordMap{
char *name;
int value;
};

UartSend UartV;
I2cSend I2cV;
I2cMemWrite MemWrite;
I2cMemRead MemRead;
SpiSend Send;
Spi spi1Config;
Spi spi2Config;
I2c I2cConfig;
Usart UsartConfig;
char wrong[10];

Mapping* parseAndReturnMappingTable(char** cmd);
int parseAndCompare(char** cmd,char* string);
int parseAndConvertNum(char** cmd);
void parseAndInsertValue(char** cmd, Mapping* table,WordMap* wordTable);
char* parseAndCompareTable(char** cmd);
char* parseWord(char** cmd);
int getValue(char** cmd,WordMap* wordingTable);
Mapping* initialDoneValue(Mapping* table);
void SpiSendValue(char** cmd);
void I2cMasterSendValue(char** cmd);
void I2cWriteMem(char** cmd);
void I2cReadMem(char** cmd);
char* getHexString(char* transmit,uint8_t* data,int total);
void UartSendData(char** cmd);
#endif // _EXECUTE_H
