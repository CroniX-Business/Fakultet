#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
//#include "C:\\Desktop\\Projekti\\jezik_c\\PP_\\LV_5\\header.h"

int main(void) {
    short int m;
    int rez;

    srand(time(NULL));
    m = (rand() % (18 - 3 + 1)) + 3;

    int **polje2D = NULL;
    polje2D = zauzimanjeMatrice(m);
    if(polje2D == NULL){
        return 1;
    }

    popunjavanje(polje2D, m);
    printf("Prva Matrica: \n");
    ispis2D(polje2D, m);

    rez = parniBroj(polje2D, m);
    printf("\n\n%d je parni\n\n", rez);

    novaMatrica(polje2D, m, rez);
    printf("Druga Matrica: \n");
    ispis2D(polje2D, m);
  
    polje2D = oslobadjanje(polje2D, m);
    return 0;
}