/*
Simple program to list all four-digit integers that reach Kaprekar's constant
in a single step. Spoiler: I count 357 numbers.

See https://en.wikipedia.org/wiki/6174
*/
#include <stdlib.h>
#include <stdio.h>

#define KAP 6174
#define SIZE 4

int comp_asc(const void* a, const void* b) {
    // Comparison function to qsort() ascending
    return(*(int*)a - *(int*)b);
}

int comp_desc(const void* a, const void* b) {
    // Comparison function to qsort() descending
    return(*(int*)b - *(int*)a);
}

int* split(int number) {
    // Split the four-digit number into an array of one-digit numbers
    int* array = malloc(SIZE * sizeof(int));

    array[0] = number / 1000;
    array[1] = (number % 1000) / 100;
    array[2] = (number % 100) / 10;
    array[3] = number % 10;

    return array;
}

int greater(int num) {
    // Sort 'num' in descending order and return that new number
    int* array = split(num);

    qsort(array, SIZE, sizeof(int), comp_desc);

    return (array[0]*1000) + (array[1]*100) + (array[2]*10) + array[3];
}

int lesser(int num){
    // Sort 'num' in ascending order and return that new number
    int* array = split(num);

    qsort(array, SIZE, sizeof(int), comp_asc);

    return (array[0]*1000) + (array[1]*100) + (array[2]*10) + array[3];
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