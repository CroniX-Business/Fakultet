#include<stdio.h>
#include<math.h>
#include<pthread.h>
#include <stdbool.h>

double array[5] = {2, 4, 6, 8, 10};

int flag[2] = {0, 0};
int turn = 0;

void* squareEl(void* arg){
    int i = *((int*) arg);
    
    while(1){
        flag[i] = 1;
        turn = 1 - i;
        while(flag[1 - i] && turn == 1 - i);
            
        for (int i = 0; i < 5; i++) {
            array[i] = array[i] * array[i];
        }
            
        printf("Kvadrirano polje: ");
        for (int i = 0; i < 5; i++) {
            printf("%.2f ", array[i]);
        }
        printf("\n");
            
        flag[i] = 0;
        sleep(1);
    }

    return NULL;
}

void* sqrtEl(void* arg){
    int i = *((int*) arg);
    while(1){
        flag[i] = 1;
        turn = 1 - i;
        while(flag[1 - i] && turn == 1 - i);
            
        for (int i = 0; i < 5; i++) {
            array[i] = sqrt(array[i]);
        }
            
        printf("Korijenovano polje: ");
        for (int i = 0; i < 5; i++) {
            printf("%.2f ", array[i]);
        }
        printf("\n");
            
        flag[i] = 0;
        sleep(1);
    }
    
    return NULL;
}

int main(){
    pthread_t threads[2];
    
    int thread_args[2] = {0, 1};
    
    pthread_create(&threads[0], NULL, squareEl, &thread_args[0]);
    pthread_create(&threads[1], NULL, sqrtEl, &thread_args[1]);
    
    for(int i=0;i<10;i++){
        flag[0] = 1;
        turn = 1;
        while(flag[1] && turn == 1);
        flag[0] = 0;
    }
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    
    return 0;
}
