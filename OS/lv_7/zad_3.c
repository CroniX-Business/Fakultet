#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <math.h>

double array[5] = {2, 4, 6, 8, 10};

bool flag1 = false;
bool flag2 = false;

int turn = 1;

void *squareEl(void *arg) {
    while (true) {
        flag1 = true;
        while (flag2) {
            if (turn == 2) {
                flag1 = false;
                while (turn == 2);
                flag1 = true;
            }
        }
        
        for (int i = 0; i < 5; i++) {
            array[i] = array[i] * array[i];
        }
        
        printf("Kvadrirano polje: ");
        for (int i = 0; i < 5; i++) {
            printf("%.2f ", array[i]);
        }
        printf("\n");
        
        turn = 2;
        flag1 = false;
        sleep(1);
    }
}

void *sqrtEl(void *arg) {
    while (true) {
        flag2 = true;
        while (flag1) {
            if (turn == 1) {
                flag2 = false;
                while (turn == 1);
                flag2 = true;
            }
        }
        for (int i = 0; i < 5; i++) {
            array[i] = sqrt(array[i]);
        }
        
        printf("Korijenovano polje: ");
        for (int i = 0; i < 5; i++) {
            printf("%.2f ", array[i]);
        }
        printf("\n");
        
        turn = 1;
        flag2 = false;
        sleep(1);
    }
}

int main() {
    pthread_t threads[2];
    int i;
    int threadId[2] = {0, 1};

    pthread_create(&threads[0], NULL, squareEl, (void *)&threadId[0]);
    pthread_create(&threads[1], NULL, sqrtEl, (void *)&threadId[0]);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}
