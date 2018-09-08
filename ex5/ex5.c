// Name: Chenyang Fang
// ID: 1663051
// email: chenyf@uw.edu
// Copyright 2018 Chenyang Fang

// for printf method
#include <stdio.h>
// for EXIT_FAILURE and EXIT_SUCCESS
// and malloc and free
#include <stdlib.h>
// for uint32_t type
#include <stdint.h>
// for boolean type
#include <stdbool.h>
// include our library
#include "Vector.h"
// for assert
#include <assert.h>
#define N 10  // Test vector length

// Print out all the elements in the given vector
static void PrintIntVector(vector_t v);

// Test the behavoir of vectors
int main(int argc, char *argv[]) {
  uint32_t i;
  vector_t v = VectorCreate(4);

  if (v == NULL)
    return EXIT_FAILURE;

  // keep track of how many
  // values we have initialized in vector
  uint32_t num = 0;
  // place some elements in the vector
  for (i = 0; i < N; ++i) {
    int *x = (int*)malloc(sizeof(int));
    element_t old;
    // initializing value
    *x = i;
    if (VectorSet(v, i, x, &old)) {
      // we have successfully placed one element
      // into the vector
      num++;
    } else {
      // we failed
      // stop placing elements into the vector
      break;
    }
  }
  if (num == N) {
    // we have successfully initialized
    // all 10 values and store them invectors
    PrintIntVector(v);
  } else {
    printf("We could not initialize our test samples\n");
  }
  // free the memory used for storing test values
  for (i = 0; i < num; ++i) {
    int* ptr = VectorGet(v, i);
    free(ptr);
  }
  // free vector
  VectorFree(v);

  if (num == N) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}

static void PrintIntVector(vector_t v) {
  uint32_t i;
  size_t length;

  assert(v != NULL);

  length = VectorLength(v);

  if (length > 0) {
    printf("[%d", *((int*)VectorGet(v, 0)));
    for (i = 1; i < VectorLength(v); ++i)
      printf(",%d", *((int*)VectorGet(v, i)));
    printf("]\n");
  }
}
