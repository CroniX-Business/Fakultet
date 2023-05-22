#include <stdio.h>
#include <stdlib.h>

int parniBroj(int **p, short int m) {
  int i, j;
  int pBroj = (*(*(p + 1) + 4));

  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      if ((i + j) > (m - 1)){
        if ((*(*(p + i) + j)) % 2 == 0) {
          if ((*(*(p + i) + j)) > pBroj) {
            pBroj = (*(*(p + i) + j));
          }
        }
      }   
    }
  }

  int rez = pBroj;
  return rez;
}