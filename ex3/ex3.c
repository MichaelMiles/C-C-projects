// name: Chenyang Fang
// Copyright 2018 Chenyang Fang

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define X 1
#define Y 2
#define Z 3

// define a structured type which contains x, y, z coordinates
typedef struct Point {
  int32_t x;
  int32_t y;
  int32_t z;
} Point3d;


Point3d* AllocatePoint3d(int32_t x, int32_t y, int32_t z);

int main(int arc, char** argv) {
  Point3d* location = AllocatePoint3d(X, Y, Z);
  if (location == NULL) {
    printf("Not able to allocate space for Point3d structure\n");
    return EXIT_FAILURE;
  } else {
    // check if all the coordinates are correctly stored
    if (location->x == X && location->y == Y && location->z ==Z) {
      // All the coordinates are correctly stored
      // print out the successful message
      printf("Successfully create a Point3d with correct values\n");
      free(location);
      return EXIT_SUCCESS;
    } else {
      // some coordinates are not correctly stored
      // print out the error message
      printf("Error: Some value is not correctly stored in Point3d\n");
      free(location);
      return EXIT_FAILURE;
    }
  }
}


// create a Point3d struct with given coordinates information
// return the pointer to that struct
Point3d* AllocatePoint3d(int32_t x, int32_t y, int32_t z) {
  Point3d* location = (Point3d*)malloc(sizeof(Point3d));
  if (location == NULL) {
    return NULL;
  }
  location->x = x;
  location->y = y;
  location->z = z;
  return location;
}
