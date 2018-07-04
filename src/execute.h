#ifndef _EXECUTE_H
#define _EXECUTE_H
#include "seperate_func.h"
#include <string.h>


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

Spi config(char array[]);
void execute(char array[]);
#endif // _EXECUTE_H
