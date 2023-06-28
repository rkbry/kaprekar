/*
Simple program to list all four-digit integers that reach Kaprekar's constant
in a single step.

See https://en.wikipedia.org/wiki/6174

*/
#include <stdlib.h>
#include <stdio.h>

int greater(int index);
int lesser(int index);

int main(void)
{
    const int KAP = 6174;

    for (int i = 1000; i < 10000; i++) {
        if (i % 1111 == 0) {
            // A minimum of two different digits required.
            continue;
        }
        if (greater(i) - lesser(i) == KAP) {
            printf("%d", i);
        }
    }
    
    return 0;
}