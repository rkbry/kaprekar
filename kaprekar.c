/*
Simple program to list all four-digit integers that reach Kaprekar's constant
in a single step.

See https://en.wikipedia.org/wiki/6174
*/
#include <stdlib.h>
#include <stdio.h>

#define KAP 6174
#define SIZE 4

int comp_asc(const void* a, const void* b) {
    return(*(int*)a - *(int*)b);
}

int comp_desc(const void* a, const void* b) {
    return(*(int*)b - *(int*)a);
}

int greater(int num) {
    /* Sort 'index' in descending order and return that new number. */
    int* array = malloc(SIZE * sizeof(int));
    array[0] = num / 1000;
    array[1] = (num % 1000) / 100;
    array[2] = (num % 100) / 10;
    array[3] = num % 10;

    qsort(array, SIZE, sizeof(int), comp_desc);

    return (array[0] * 1000) + (array[1] * 100) + (array[2] * 10) + array[3];
}

int lesser(int num){
    /* Sort 'index' in ascending order and return that new number. */
    int* array = malloc(SIZE * sizeof(int));
    array[0] = num / 1000;
    array[1] = (num % 1000) / 100;
    array[2] = (num % 100) / 10;
    array[3] = num % 10;

    qsort(array, SIZE, sizeof(int), comp_asc);

    return (array[0] * 1000) + (array[1] * 100) + (array[2] * 10) + array[3];
}

int main(void) {
    for (int i = 1000; i < 10000; i++) {
        if (i % 1111 == 0) {
            // A minimum of two different digits required.
            continue;
        }
        
        if ((greater(i) - lesser(i)) == KAP) {
            printf("%d\n", i);
        }
    }
    return 0;
}