#include "execute.h"
#include "Exception.h"
//#include "CExeption.h"
#include "error.h"
#include "stm32f1xx_hal.h"




Mapping Spi1TableMapping[] = {
{"Mode",&spi1Config.Mode,0},
{"Direction",&spi1Config.Direction,0},
 {"DataSize",&spi1Config.DataSize,0},
 {"CLKPolarity",&spi1Config.CLKPolarity,0},
 {"CLKPhase",&spi1Config.CLKPhase,0},
 {"NSS",&spi1Config.NSS,0},
 {"BaudRatePrescaler",&spi1Config.BaudRatePrescaler,0},
 {"FirstBit",&spi1Config.FirstBit,0},
 {"TIMode",&spi1Config.TIMode,0},
 {"CRCCalculation",&spi1Config.CRCCalculation,0},
 {"CRCPolynomial",&spi1Config.CRCPolynomial,0},
{NULL,NULL,0},
};

Mapping Spi2TableMapping[] = {
{"Mode",&spi2Config.Mode,0},
{"Direction",&spi2Config.Direction,0},
 {"DataSize",&spi2Config.DataSize,0},
 {"CLKPolarity",&spi2Config.CLKPolarity,0},
 {"CLKPhase",&spi2Config.CLKPhase,0},
 {"NSS",&spi2Config.NSS,0},
 {"BaudRatePrescaler",&spi2Config.BaudRatePrescaler,0},
 {"FirstBit",&spi2Config.FirstBit,0},
 {"TIMode",&spi2Config.TIMode,0},
 {"CRCCalculation",&spi2Config.CRCCalculation,0},
 {"CRCPolynomial",&spi2Config.CRCPolynomial,0},

{NULL,NULL,0},
};

Mapping I2cTableMapping[]={
  {"clockSpeed",&I2cConfig.ClockSpeed,0},
  {"dutyCycle",&I2cConfig.DutyCycle,0},
  {"OwnAddress",&I2cConfig.OwnAddress1,0},
  {"AddressingMode",&I2cConfig.AddressingMode,0},
  {"DualAddressMode",&I2cConfig.DualAddressMode,0},
  {"OwnAddress2",&I2cConfig.OwnAddress2,0},
  {"GeneralCallMode",&I2cConfig.GeneralCallMode,0},
  {"NoStretchMode",&I2cConfig.NoStretchMode,0},
  {NULL,NULL,0},
};

Mapping UsartTableMapping[]={
  {"WordLength",&UsartConfig.WordLength,0},
  {"BaudRate",&UsartConfig.BaudRate,0},
  {"StopBit",&UsartConfig.StopBit,0},
  {"Parity",&UsartConfig.Parity,0},
  {"Mode",&UsartConfig.Mode,0},
  {"ClkPolarity",&UsartConfig.ClkPolarity,0},
  {"ClkPhase",&UsartConfig.ClkPhase,0},
  {"clkLastBit",&UsartConfig.clkLastBit,0},
  {NULL,NULL,0},
};
WordMap UsartMappingTable[] ={
  {"8bit",USART_WORDLENGTH_8B},
  {"9bit",USART_WORDLENGTH_9B},
  {"1",USART_STOPBITS_1},
  {"0.5",USART_STOPBITS_0_5},
  {"2",USART_STOPBITS_2},
  {"1.5",USART_STOPBITS_1_5},
  {"none",USART_PARITY_NONE},
  {"even",USART_PARITY_EVEN},
  {"odd",USART_PARITY_ODD},
  {"rx",USART_MODE_RX},
  {"tx",USART_MODE_TX},
  {"txrx",USART_MODE_TX_RX},
  {"low",USART_POLARITY_LOW},
  {"high",USART_POLARITY_HIGH},
  {"edge1",USART_PHASE_1EDGE},
  {"edge2",USART_PHASE_2EDGE},
  {"enable",USART_LASTBIT_DISABLE},
  {"disable",USART_LASTBIT_ENABLE},
  {NULL,NULL,0},
};
WordMap I2cWordMapping[] ={
  {"2dutycycle",I2C_DUTYCYCLE_2},
  {"16dutyCycle",I2C_DUTYCYCLE_16_9},
  {"7bit",I2C_ADDRESSINGMODE_7BIT},
  {"10bit",I2C_ADDRESSINGMODE_10BIT},
  {"dual_disable",I2C_DUALADDRESS_DISABLE},
  {"dual_able",I2C_DUALADDRESS_ENABLE},
  {"general_disable",I2C_GENERALCALL_DISABLE},
  {"dual_disable",I2C_DUALADDRESS_ENABLE},
  {"general_enable",I2C_GENERALCALL_ENABLE},
  {"general_disable",I2C_GENERALCALL_DISABLE},
  {"nonstretch_enable",I2C_NOSTRETCH_ENABLE},
  {"nonstrecth_disable",I2C_NOSTRETCH_DISABLE},
  {NULL,NULL,0},
};
WordMap SpiWordMapping[] ={
  {"Low",0},
  {"High",1},
  {"slave",SPI_MODE_SLAVE},
  {"master", SPI_MODE_MASTER},
 {"2line",SPI_DIRECTION_2LINES},
 {"2lineRXonly",SPI_DIRECTION_2LINES_RXONLY},
 {"1line",SPI_DIRECTION_1LINE},
 {"8bit",SPI_DATASIZE_8BIT},
 {"16bit",SPI_DATASIZE_16BIT},
 {"parityLow",SPI_POLARITY_LOW},
 {"parityHigh",SPI_POLARITY_HIGH},
 {"1edge",SPI_PHASE_1EDGE},
 {"2edge",SPI_PHASE_2EDGE},
 {"2",SPI_BAUDRATEPRESCALER_2},
 {"4",SPI_BAUDRATEPRESCALER_4},
 {"8",SPI_BAUDRATEPRESCALER_8},
 {"16",SPI_BAUDRATEPRESCALER_16},
 {"32",SPI_BAUDRATEPRESCALER_32},
 {"64",SPI_BAUDRATEPRESCALER_64},
 {"128",SPI_BAUDRATEPRESCALER_128},
 {"256",SPI_BAUDRATEPRESCALER_256},
 {"msb",SPI_FIRSTBIT_MSB},
 {"lsb",SPI_FIRSTBIT_LSB},
 {"crcDisable",SPI_CRCCALCULATION_DISABLE},
 {"crcEnable",SPI_CRCCALCULATION_ENABLE},
 {"Txe",SPI_IT_TXE},
 {"Rxne",SPI_IT_RXNE},
 {"Err",SPI_IT_ERR},
  {NULL,0},
};

void SpiSendValue(char** cmd)
{

	Send.total = 0;
  while(**cmd != 10){
    Send.value[Send.total] = parseAndConvertNum(cmd);

    Send.total++;
  }

}

void I2cMasterSendValue(char** cmd)
{
	I2cV.total=0;
	I2cV.address = parseAndConvertNum(cmd);
	 while(**cmd != 10){
		 I2cV.value[I2cV.total] = parseAndConvertNum(cmd);
		 I2cV.total++;
	  }
}

void I2cWriteMem(char** cmd)
{
	MemWrite.total=0;
	MemWrite.address = parseAndConvertNum(cmd);
	MemWrite.MemAddr = parseAndConvertNum(cmd);
	 while(**cmd != 10){
		 MemWrite.value[I2cV.total] = parseAndConvertNum(cmd);
		 MemWrite.total++;
		  }
}

void I2cReadMem(char** cmd){

	MemRead.address = parseAndConvertNum(cmd);
	MemRead.MemAddr = parseAndConvertNum(cmd);
}

void UartSendData(char** cmd){
	UartV.total=0;
	 while(**cmd != 10){
		 UartV.value[UartV.total] = parseAndConvertNum(cmd);
		 UartV.total++;
	 }

}
int parseAndCompare(char** cmd,char* string)
{
  while(**cmd == 32 || **cmd == 61 || **cmd == 10){
    *cmd +=1;
  }
  char* originline = *cmd;
  while(**cmd != 32 && **cmd != 10 ){
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
  while(**cmd == 32 || **cmd == 61){
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

void parseAndInsertValue(char** cmd, Mapping* table,WordMap* wordTable)
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
if(table[i].name ==  "BaudRate"){
    *cmd+=1;
      value = parseAndConvertNum(cmd);
}
if(table[i].name ==  "clockSpeed"){
    *cmd+=1;
      value = parseAndConvertNum(cmd);
}
while(**cmd == 61){
  *cmd+=1;
  value = getValue(cmd,wordTable);
  printf("%i\n",*table[i].value);
}
*table[i].value = value;
table[i].done = 1;
}

char* parseAndCompareTable(char** cmd)
{
  char* originline = *cmd;
  Mapping *mappingTable;
  WordMap *wordMappingTable;
  if(parseAndCompare(cmd,"SpiWrite")==1){
    SpiSendValue(cmd);
    return "SpiWrite";
  }
  if(parseAndCompare(cmd,"I2CWrite")==1){
	  I2cMasterSendValue(cmd);
     return "I2cWrite";
   }
  if(parseAndCompare(cmd,"I2CMemWrite")==1){
	  I2cWriteMem(cmd);
       return "I2CMemWrite";
     }
  if(parseAndCompare(cmd,"I2CMemRead")==1){
	  I2cReadMem(cmd);
        return "I2CMemRead";
      }
  if(parseAndCompare(cmd,"UsartSend")==1){
	  UartSendData(cmd);
       return "UsartSend";
     }
  if(parseAndCompare(cmd,"UsartRead")==1){

         return "UsartRead";
       }
  if(parseAndCompare(cmd,"Spi1Config")==1){
    *cmd = originline;
    wordMappingTable = SpiWordMapping;
    mappingTable = parseAndReturnMappingTable(cmd);
    mappingTable=initialDoneValue(mappingTable);
    while(**cmd != 10){
    parseAndInsertValue(cmd, mappingTable,wordMappingTable);
    while(**cmd == 32){
      *cmd +=1;
    }
  }
  printf("%c\n",**cmd);
  return "SpiConfig";
}
if(parseAndCompare(cmd,"Spi2Config")==1){
  *cmd = originline;
  wordMappingTable = SpiWordMapping;
  mappingTable = parseAndReturnMappingTable(cmd);
  mappingTable=initialDoneValue(mappingTable);
  while(**cmd != 10){
  parseAndInsertValue(cmd, mappingTable,wordMappingTable);
  while(**cmd == 32){
    *cmd +=1;
  }
}
printf("%c\n",**cmd);
return "SpiConfig";
}
if(parseAndCompare(cmd,"I2cConfig")==1){
    *cmd = originline;
  wordMappingTable = I2cWordMapping;
  mappingTable = parseAndReturnMappingTable(cmd);
  mappingTable=initialDoneValue(mappingTable);
  while(**cmd != 10){
  parseAndInsertValue(cmd, mappingTable,wordMappingTable);
  while(**cmd == 32){
    *cmd +=1;
  }
}
printf("%c\n",**cmd);
return "I2cConfig";
}
if(parseAndCompare(cmd,"UsartConfig")==1){
    *cmd = originline;
  wordMappingTable = UsartMappingTable;
  mappingTable = parseAndReturnMappingTable(cmd);
  mappingTable=initialDoneValue(mappingTable);
  while(**cmd != 10){
  parseAndInsertValue(cmd, mappingTable,wordMappingTable);
  while(**cmd == 32){
    *cmd +=1;
  }
}
printf("%c\n",**cmd);
return "UsartConfig";
}
else{
  char* error = parseWord(cmd);
  throwException(NO_TABLE,"Didnt have this table",error);
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
  else if(parseAndCompare(cmd,"I2cConfig")==1){
    map1 = I2cTableMapping;
  }
  else if(parseAndCompare(cmd,"UsartConfig")==1){
    map1 = UsartTableMapping;
  }
  else{
    char* error = parseWord(cmd);
    throwException(NO_TABLE,"Didnt have this table",error);
  }
   return map1;
}

Mapping* initialDoneValue(Mapping* table)
{
  int i =0;
  while(table[i].name != NULL){
    table[i].done = 0;
    i++;
  }
  return table;
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

int getValue(char** cmd,WordMap* wordingTable)
{
  int i=0;
  int value;
  char* originline = *cmd;
  while(wordingTable[i].name != NULL){
    if(parseAndCompare(cmd,wordingTable[i].name)==1){
      value = wordingTable[i].value;
      return value;
    }
    else
    {
      i++;
    }
  }
  while(wordingTable[i].name == NULL){
    *cmd = originline;
    char* error = parseWord(cmd);

      throwException(NOT_IN_WORDMAP,"Not in wordMap",error);
  }

}

char* getHexString(char* transmit,uint8_t* data,int total){
	int i = 0;
	int j = 0;
	while(i<total){
    sprintf(transmit+j,"%2x ",data[i]);

		i++;
		j=j+2;
	}
  return transmit;
}
