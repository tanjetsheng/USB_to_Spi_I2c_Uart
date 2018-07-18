#include "execute.h"
#include "Exception.h"
//#include "CExeption.h"
#include "error.h"

Mapping Spi1TableMapping[] = {
{"Mode",&spi1Config.Mode,0},
{"Direction",&spi1Config.Direction,0},
// {"DataSize",&spi1Config.DataSize,0},
// {"CLKPolarity",&spi1Config.CLKPolarity,0},
// {"CLKPhase",&spi1Config.CLKPhase,0},
// {"NSS",&spi1Config.NSS,0},
// {"BaudRatePrescaler",&spi1Config.BaudRatePrescaler,0},
// {"FirstBit",&spi1Config.FirstBit,0},
// {"TIMode",&spi1Config.TIMode,0},
// {"CRCCalculation",&spi1Config.CRCCalculation,0},
// {"CRCPolynomial",&spi1Config.CRCPolynomial,0},
{NULL,NULL,0},
};

Mapping Spi2TableMapping[] = {
{"Mode",&spi2Config.Mode,0},
{"Direction",&spi2Config.Direction,0},
// {"DataSize",&spi2Config.DataSize,0},
// {"CLKPolarity",&spi2Config.CLKPolarity,0},
// {"CLKPhase",&spi2Config.CLKPhase,0},
// {"NSS",&spi2Config.NSS,0},
// {"BaudRatePrescaler",&spi2Config.BaudRatePrescaler,0},
// {"FirstBit",&spi2Config.FirstBit,0},
// {"TIMode",&spi2Config.TIMode,0},
// {"CRCCalculation",&spi2Config.CRCCalculation,0},
// {"CRCPolynomial",&spi2Config.CRCPolynomial,0},

{NULL,NULL,0},
};

WordMap WordMapping[] ={
  {"Low",0},
  {"High",1},
  {NULL,0},
};


int parseAndCompare(char** cmd,char* string)
{
  while(**cmd == 32){
    *cmd +=1;
  }
  char* originline = *cmd;
  while(**cmd != 32){
  if(**cmd==*string){
    printf("%c",**cmd);
    *cmd+= 1;
    string++;
  }
  else{
    *cmd = originline;
    return 0;
  }
}

return 1;
}

int parseAndConvertNum(char** cmd)
{
  int result = 0;
  while(**cmd == 32){
    *cmd +=1;
  }
  char* originline = *cmd;
  while(**cmd != 32 && **cmd != 10){
  if(58>(**cmd)&&(**cmd)>47){
    result = (result * 10) + ((**cmd)-48);
    *cmd+=1;
  }
  else{
    *cmd = originline;
    return 0;
  }
  }
  return result;
}

void parseAndInsertValue(char** cmd, Mapping* table)
{
  int i =0;
  int value =0;
char* originline = *cmd;
  while(**cmd != 61 && table[i].name != NULL && **cmd != 10){
  if(parseAndCompare(cmd,table[i].name)==1){
      *cmd +=1;
    while(**cmd == 32){
      *cmd +=1;
    }
  }
  else
  {
    i++;
  }
}
 if(table[i].done != 0 ){
  *cmd = originline;
  char* error = parseWord(cmd);

    throwException(CONFIGURED,"already configure",error);
 }
if(table[i].name == NULL){
  *cmd = originline;
  char* error = parseWord(cmd);

    throwException(NOT_IN_TABLE,"Not in the table",error);
}
while(**cmd == 61){
  *cmd+=1;
  value = getValue(cmd);
  *table[i].value = value;
  table[i].done = 1;
  printf("%i\n",*table[i].value);
}
}

void parseAndCompareTable(char** cmd)
{
  Mapping *mappingTable;
  mappingTable = parseAndReturnMappingTable(cmd);
  while(**cmd != 10){
  parseAndInsertValue(cmd, mappingTable);
  while(**cmd == 32){
    *cmd +=1;
  }
  printf("%c\n",**cmd);
}
}


Mapping* parseAndReturnMappingTable(char** cmd){
  Mapping *map1;

  if(parseAndCompare(cmd,"Spi1Config")==1){
    map1 = Spi1TableMapping;
  }
  else if(parseAndCompare(cmd,"Spi2Config")==1){
    map1 = Spi2TableMapping;
  }
  else{
    char* error = parseWord(cmd);
    throwException(NO_TABLE,"Didnt have this table",error);
  }
   return map1;
}

char* parseWord(char** cmd)
{
  int i=0;
  while(**cmd == 32){
    *cmd +=1;
  }
    while(**cmd != 32)
    {
      wrong[i] = **cmd;
      *cmd +=1;
      i++;

    }
    printf("%s\n",wrong );
    return wrong;
}

int getValue(char** cmd)
{
//  WordMap *WordMapping;
  int i=0;
  int value;
  char* originline = *cmd;
  while(WordMapping[i].name != NULL){
    if(parseAndCompare(cmd,WordMapping[i].name)==1){
      value = WordMapping[i].value;
      return value;
    }
    else
    {
      i++;
    }
  }
  while(WordMapping[i].name == NULL){
    *cmd = originline;
    char* error = parseWord(cmd);

      throwException(NOT_IN_WORDMAP,"Not in wordMap",error);
  }

}
