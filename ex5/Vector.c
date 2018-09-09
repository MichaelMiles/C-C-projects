// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang

// for assert
#include <assert.h>
// for boolean values
#include <stdbool.h>
// for uint32_t type
#include <stdint.h>
// for size_t type
#include <stdio.h>
// for malloc and free
#include <stdlib.h>
#include "./Vector.h"


// On sucess, Returns a copy of arry with new length newLen.  If newLen < oldLen
// then the returned array is clipped.  If newLen > oldLen, then the
// resulting array will be padded with NULL elements.
// return NULL if on failure
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen);

vector_t VectorCreate(size_t n) {
  vector_t v = (vector_t)malloc(sizeof(struct vector_t));
  if (v == NULL) {
    return NULL;
  }
  v->arry = (element_t*)malloc(n*sizeof(element_t));
  if (v->arry == NULL) {
     // need to free v before return
     VectorFree(v);
     return NULL;
  }
  // initialize length
  v->length = 0;
  return v;
}

void VectorFree(vector_t v) {
  assert(v != NULL);
  free(v->arry);
  free(v);
}

bool VectorSet(vector_t v, uint32_t index, element_t e, element_t *prev) {
  assert(v != NULL);

  if (index >= v->length) {
    size_t newLength = index+1;

    element_t* newArray = ResizeArray(v->arry, v->length, newLength);
    // check if malloc erro from ResizeArray
    if (newArray == NULL) {
        return false;
    }
    // otherwise, no error
    // update vector
    free(v->arry);
    v->arry = newArray;
    v->length = newLength;
    *prev = NULL;
  } else {
    // returns the previous nth element_t in prev
    *prev = v->arry[index];
  }

  v->arry[index] = e;

  return true;
}

element_t VectorGet(vector_t v, uint32_t index) {
  assert(v != NULL);
  // check if the index is out of bounds
  assert(index < VectorLength(v));
  return v->arry[index];
}

size_t VectorLength(vector_t v) {
  assert(v != NULL);
  return v->length;
}

static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen) {
  uint32_t i;
  size_t copyLen = oldLen > newLen ? newLen : oldLen;
  element_t *newArry;

  assert(arry != NULL);

  newArry = (element_t*)malloc(newLen*sizeof(element_t));

  if (newArry == NULL) {
    return NULL;  // malloc error!!!
  }
  // Copy elements to new array
  for (i = 0; i < copyLen; ++i)
    newArry[i] = arry[i];

  // Null initialize rest of new array
  for (i = copyLen; i < newLen; ++i)
    newArry[i] = NULL;

  return newArry;
}

