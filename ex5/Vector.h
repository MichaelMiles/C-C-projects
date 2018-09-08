// name: Chenyang Fang
// ID: 1663051
// email: chenyf@uw.edu
// Copyright 2018 Chenyang Fang

#ifndef VECTOR_H
#define VECTOR_H
// for uint32_t type
#include <stdint.h>

// An arbitrary pointer to represent an element in the vector.
typedef void* element_t;

// An expandable array of element_ts.
typedef struct vector_t {
  size_t length;
  element_t *arry;
} *vector_t;

// On success, return vector_t with an initial length of n.
// On failure, returns NULL.
extern vector_t VectorCreate(size_t n);

// Frees the memory allocated for the vector_t v.  Assumes v != NULL.
extern void VectorFree(vector_t v);

// Assume v != NULL
// Sets the nth element of v to be e.
// On success, returns true and return the previous
// nth element in prev if it existed, NULL if it didn't
// On failure, return false
// note that this method is not responsible for
// freeing e
extern bool VectorSet(vector_t v, uint32_t index, element_t e, element_t *prev);

// Returns the element at the given index within v.  Assumes v != NULL.
extern element_t VectorGet(vector_t v, uint32_t index);

// Returns the length of v.  Assumes v != NULL.
extern size_t VectorLength(vector_t v);


#endif
