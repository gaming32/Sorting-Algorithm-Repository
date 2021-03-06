#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "double_insertion.h"
#define SORT_TYPE DOUBLE_INSERTION_TYPE
#define SORT_FUNC double_insertion

#define LENGTH 32
#define SEED   time(NULL)


SORT_TYPE randrange(SORT_TYPE high) {
    return (SORT_TYPE)(rand() * high / RAND_MAX);
}


void printArray(SORT_TYPE* array, int length) {
    printf("[%i", array[0]);
    for (int i = 1; i < length; i++) {
        printf(", %i", array[i]);
    }
    printf("]\n");
}


int main() {
    SORT_TYPE* array = (int*)malloc(LENGTH * sizeof(SORT_TYPE));
    srand(SEED);
    for (int i = 0; i < LENGTH; i++) {
        array[i] = randrange(LENGTH);
    }
    printArray(array, LENGTH + 6);
    SORT_FUNC(array, LENGTH);
    printArray(array, LENGTH + 6);
}
