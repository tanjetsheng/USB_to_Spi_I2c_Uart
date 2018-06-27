#include "seperate_func.h"
#include <string.h>





char** seperate(char *string)
{
char** newString;
int i,j,ctr;
newString=(char **)malloc(sizeof(string));
    for (int i=0;i<sizeof(string);i++)
    {
        newString[i]=(char*)malloc(sizeof(string));
    }
    j=0;
    ctr=0;
    for(i=0;i<=(strlen(string));i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(string[i]==' '||string[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=string[i];
            j++;
        }
    }
  //  printf("Strings or words after split by space are :\n");
    for(i=0;i < ctr;i++)
        printf(" %s\n",newString[i]);

  //  printf("new string pointer adr = %s",newString[1]);
    return newString;
}
