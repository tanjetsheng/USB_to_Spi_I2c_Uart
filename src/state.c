#include "state.h"


void state_machine(char* string){
  char** data;
  data = seperate(string);

  enum States state;

  switch(state){
    case IDLE:
    printf("IDLE");
    //printf("\nans = %s",data[0]);
    if(strcmp(data[0],'spi')==0){
      state = SPI;
    }
    else if(strcmp(data[0],'I2c')==0){
      state = I2C;
    }
    else{
      state = Error;
    }


    break;

    case SPI:
    printf("Spi");


    break;

    case I2C:


    break;

    case Error:
    printf("didnt have this selection");
    state = IDLE;
    break;

    default:
    state = IDLE;
    break;

  }
}
