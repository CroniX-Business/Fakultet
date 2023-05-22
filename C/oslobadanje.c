#include <stdio.h>
#include <stdlib.h>

int** oslobadjanje(int **p, short int m) {
  int i;
  
  for (i = 0; i < m; i++) {
    free(*(p + i));
  }
  
  free(p);
  
  return NULL;
}