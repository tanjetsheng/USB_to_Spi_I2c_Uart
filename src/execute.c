#include "execute.h"
char* ExArray;
char* value;
void execute(char array[]){

  ExArray = extract(array);
  printf("input = %s\n",ExArray);
if(strcmp(ExArray,"SpiConfig")==0)
{

  array=shifter(array,strlen(ExArray)+1);
  printf("%s\n",array);
  //memset(ExArray,0,sizeof(ExArray));

  config(array);
}
else{
printf("these is not include in the selection");
}

}

Spi config(char array[]){
  Spi s;

  ExArray = extract(array);

    if(strcmp(ExArray,"mode")==0){
    //  printf("in mode" );
    array=shifter(array,strlen(ExArray)+1);

    value = extract(array);
    if(*value <= 50){
    s.Mode = *value;
    printf("mode = %i\n",s.Mode);
  }
    }

}
