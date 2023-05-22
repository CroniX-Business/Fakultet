#include <stdio.h>
#include <stdlib.h>

int** zauzimanjeMatrice(short int m) {
    int **polje2D = NULL;

    polje2D = (int**)calloc(m, sizeof(int*));
    if(polje2D == NULL){
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        *(polje2D + i) = (int*)calloc(m, sizeof(int));
        if(*(polje2D + i) == NULL) {
            return NULL;
        }
    }
    
    return polje2D;
}