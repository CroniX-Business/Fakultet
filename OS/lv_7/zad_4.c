#include <stdio.h>
#include <math.h>
#include <pthread.h>

#define ARRAY_SIZE 5

int array[ARRAY_SIZE] = {2, 4, 6, 8, 10};
int turn = 0;
int interested[2] = {0, 0};

void *squareElements(void *arg) {
    int self = *((int *)arg);

    while (1) {
        interested[self] = 1;
        turn = 1 - self;

        while (interested[1 - self] && turn == 1 - self) {
            // Čekaj drugu nit
        }

        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = array[i] * array[i];
        }
        
        printf("Kvadrirano polje: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        interested[self] = 0;
    }
    
    pthread_exit(NULL);
}

void *sqrtElements(void *arg) {
    int self = *((int *)arg);

    while (1) {
        interested[self] = 1;
        turn = 1 - self;

        while (interested[1 - self] && turn == 1 - self) {
            // Čekaj drugu nit
        }

        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = sqrt(array[i]);
        }
        
        printf("Korijenovano polje: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        interested[self] = 0;
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
