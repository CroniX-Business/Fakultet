#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popunjavanje(int **p, short int m) {
    int i, j;

    srand(time(NULL));;
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            *(*(p + i) + j) = (rand() % (250 - (-1550) + 1)) + (-1550);
        }
    }
}   