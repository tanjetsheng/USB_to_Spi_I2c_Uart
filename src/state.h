#ifndef _STATE_H
#define _STATE_H
#include "seperate_func.h"
#include "stdlib.h"

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

enum States {
    IDLE,
    SPI,
    I2C,
    Error,
} States;

  enum States state;
void state_machine(char* string);

#endif // _STATE_H
