#include <stdio.h>
#include <stdlib.h>

void novaMatrica(int **p, short int m, int rez) {
  int i, j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      if ((i + j) < (m - 1)){
        (*(*(p + i) + j)) = rez;
      }
    }
  } 
}