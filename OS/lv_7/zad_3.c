#include <stdio.h>
#include <math.h>
#include <pthread.h>

#define ARRAY_SIZE 5

int array[ARRAY_SIZE] = {2, 4, 6, 8, 10};
int turn = 0;
int flag[2] = {0, 0};

void *squareElements(void *arg) {
    int self = *((int *)arg);

    while (1) {
        flag[self] = 1;
        while (flag[1 - self]) {
            if (turn != self) {
                flag[self] = 0;
                while (turn != self) {}
                flag[self] = 1;
            }
        }

        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = array[i] * array[i];
        }
        
        printf("Kvadrirano polje: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        turn = 1 - self;
        flag[self] = 0;
    }
    
    pthread_exit(NULL);
}

void *sqrtElements(void *arg) {
    int self = *((int *)arg);

    while (1) {
        flag[self] = 1;
        while (flag[1 - self]) {
            if (turn != self) {
                flag[self] = 0;
                while (turn != self) {}
                flag[self] = 1;
            }
        }

        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = sqrt(array[i]);
        }
        
        printf("Korijenovano polje: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        turn = 1 - self;
        flag[self] = 0;
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t squareThread, sqrtThread;
    int threadId[2] = {0, 1};
    
    pthread_create(&squareThread, NULL, squareElements, (void *)&threadId[0]);
    pthread_create(&sqrtThread, NULL, sqrtElements, (void *)&threadId[1]);
    
    pthread_join(squareThread, NULL);
    pthread_join(sqrtThread, NULL);
    
    return 0;
}
