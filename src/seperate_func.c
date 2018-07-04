#include "seperate_func.h"
#include <string.h>


char* extract(char array[]){
  int i=0;

   static char extracted[10];
   memset(extracted,0,sizeof(extracted));
  while(array[i] != ' ' && array[i] != '='){
    extracted[i]=array[i];
    i++;
  }
//  printf("%skl\n",extracted );
//extracted[i] = "\0";
  return extracted;
}

char* shifter(char array[],int num)
 {
   static char shifted[100];
  for(int i=0;i<strlen(array);i++){
    shifted[i]=array[i+num];
  }
  return shifted;
}
