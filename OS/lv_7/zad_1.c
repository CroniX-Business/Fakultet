#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int array[ARRAY_SIZE] = {5, 2, 9, 1, 7, 3, 8, 6, 4, 10};

void *findMax(void *arg) {
    int max = array[0];
    
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    
    printf("Najveći element polja: %d\n", max);
    
    pthread_exit(NULL);
}

void *findMin(void *arg) {
    int min = array[0];
    
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    
    printf("Najmanji element polja: %d\n", min);
    
    pthread_exit(NULL);
}

void *calculateAverage(void *arg) {
    int sum = 0;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    
    double average = (double) sum / ARRAY_SIZE;
    
    printf("Aritmetička sredina elemenata polja: %.2f\n", average);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t maxThread, minThread, averageThread;
    
    pthread_create(&maxThread, NULL, findMax, NULL);
    pthread_create(&minThread, NULL, findMin, NULL);
    pthread_create(&averageThread, NULL, calculateAverage, NULL);
    
    pthread_join(maxThread, NULL);
    pthread_join(minThread, NULL);
    pthread_join(averageThread, NULL);
    
    return 0;
}
