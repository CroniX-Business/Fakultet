#include <stdio.h>
#include <stdlib.h>

void ispis2D(int **p, short int m) {
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("%i ", *(*(p + i) + j));
        }
    printf("\n");
    }
}