#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

#define ARRAY_SIZE 5

int array[ARRAY_SIZE] = {2, 4, 6, 8, 10};

void *squareElements(void *arg) {
    while (1) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = array[i] * array[i];
        }
        
        printf("Kvadrirano polje: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        
        sleep(1);
    }
    
    pthread_exit(NULL);
}

void *sqrtElements(void *arg) {
    while (1) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = sqrt(array[i]);
        }
        
        printf("Korijenovano polje: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        
        sleep(1);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t squareThread, sqrtThread;
    
    pthread_create(&squareThread, NULL, squareElements, NULL);
    pthread_create(&sqrtThread, NULL, sqrtElements, NULL);
    
    pthread_join(squareThread, NULL);
    pthread_join(sqrtThread, NULL);
    
    return 0;
}
