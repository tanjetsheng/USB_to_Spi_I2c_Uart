#include "Exception.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>


Exception *createException(char *msg, int errorCode){
  Exception *e = malloc(sizeof(Exception));
  e -> msg = msg;
  e -> errorCode = errorCode;
  return e;
}


void throwException(int errorCode, char *message,void *data ,...) {
	char *error;
	error = malloc(100);
  va_list args;
  char *buffer;
  int length;
  Exception *e;

  va_start(args, message);
  e = malloc(sizeof(Exception));

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length + 1);
  vsnprintf(buffer, length + 1, message, args);

  e->msg = buffer;
  e->errorCode = errorCode;
  e->data = data;
  sprintf(error,"%s---> [%s]\n (err=%d)\n", e->msg,e->data, e->errorCode);
  CDC_Transmit_FS(error,strlen(error));
  free(error);
  Throw(e);

}

void freeException(Exception *e) {
  if(e) {
    if(e->msg)

      free(e->msg);
    free(e);
  }

}

void dumpException(Exception *e) {

  printf("%s---> [%s]\n (err=%d)\n", e->msg,e->data, e->errorCode);

}
