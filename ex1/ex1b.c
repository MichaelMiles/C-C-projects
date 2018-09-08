// name: Chenyang Fang
// ID: 1663051
// email: chenyf@uw.edu
// Copyright 2018 Chenyang Fang

#include <stdio.h>
#include <stdint.h>  // for more specified integer types
#include <inttypes.h>

// declaration of function CopyAndSort
void CopyAndSort(int32_t src[], int32_t dest[], uint32_t size);
// declaration of function printArray
void printArray(int32_t src[], uint32_t size);

int main(int argc, char* argv[]) {
    int32_t src[] = {3, 2, -5, 7, 13, 4, 1, 7, 8, -8, 6};
    int32_t dest[11];
    CopyAndSort(src, dest, 11);
    printArray(dest, 11);
}


// copy and sort the given src array into the given dest array
void CopyAndSort(int32_t src[], int32_t dest[], uint32_t size) {
    uint32_t num = 0;  // keeping track of how many values we have sorted

    for (uint32_t i = 0; i < size; i ++) {
        // the index of dest array at which we should insert
        // src[i] at
        uint32_t index = 0;
        for (uint32_t j = 0; j < num; j ++) {
            if (dest[j] > src[i]) {
                // we find the suitable place for src[i]
                // in dest array
                index = j;
                break;
            }
            index++;
        }
        // insert src[i] into the dest array
        for (uint32_t k = num; k > index; k --) {
            dest[k] = dest[k - 1];
        }
        dest[index] = src[i];
        // updating our progress of sorting
        num++;
    }
}

// output the int values in the given src array
void printArray(int32_t src[], uint32_t size) {
    for (uint32_t index = 0; index < size; index ++) {
        printf("%" PRId32 " ", src[index]);
    }
    printf("\n");
}
