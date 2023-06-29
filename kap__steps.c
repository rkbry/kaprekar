/*
Given a four-digit number with at least two unique digits, show the steps
necessary to reach Kaprekar's constant, 6174.

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

int* split(int num) {
    int* array = malloc(SIZE * sizeof(int));

    array[0] = num / 1000;
    array[1] = (num % 1000) / 100;
    array[2] = (num % 100) / 10;
    array[3] = num % 10;

    return array;
}

int greater(int num) {
    /* Sort 'index' in descending order and return that new number. */
    int* array = split(num);
    qsort(array, SIZE, sizeof(int), comp_desc);
    return (array[0] * 1000) + (array[1] * 100) + (array[2] * 10) + array[3];
}

int lesser(int num){
    /* Sort 'index' in ascending order and return that new number. */
    int* array = split(num);
    qsort(array, SIZE, sizeof(int), comp_asc);
    return (array[0] * 1000) + (array[1] * 100) + (array[2] * 10) + array[3];
}

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Usage: %s <four-digit number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int number = atoi(argv[1]);

    if (number < 1000 || number > 9998) {
        printf("Error: integer argument not in range. Usage: %s <four-digit number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (number % 1111 == 0) {
        printf("Error: the number must have at least two different digits. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    // Are we finally ready yet?
    do {
        int new_number = greater(number) - lesser(number);
        printf("%4d: %4d - %4d = %4d\n", number, greater(number), lesser(number), new_number);
        number = new_number;
    } while(number != KAP);

    return EXIT_SUCCESS;
}