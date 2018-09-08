// Name: Chenyang Fang
// student number: 1663051
// uw email: chenyf@uw.edu
// Copyright 2018 Chenyang Fang
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// declaration of function DumpHex
void DumpHex(void* data, int byteLen);

int main(int argc, char **argv) {
  char     charVal = '0';
  int32_t  intVal = 1;
  float    floatVal = 1.0;
  double   doubleVal  = 1.0;

  typedef struct {
    char     charVal;
    int32_t  intVal;
    float    floatVal;
    double   doubleVal;
  } Ex2Struct;
  Ex2Struct structVal = { '0', 1, 1.0, 1.0 };

  DumpHex(&charVal, sizeof(char));
  DumpHex(&intVal, sizeof(int32_t));
  DumpHex(&floatVal, sizeof(float));
  DumpHex(&doubleVal, sizeof(double));
  DumpHex(&structVal, sizeof(structVal));

  return EXIT_SUCCESS;
}

void DumpHex(void* data, int byteLen) {
  uint8_t* index = (uint8_t*)data;
  printf("The %d bytes starting at %p are:", byteLen, data);
  for (int i = 0; i < byteLen; i ++) {
    // interate through each byte and print out the result
    printf(" %02" PRIx8, *index);
    index++;
  }
  // for formatting
  printf("\n");
}
