#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define MAX_SIZE 100

void generateNumber(int shmid, int n) {
    int* shmem = (int*)shmat(shmid, 0, 0);
    if (shmem == (int*)-1) {
        perror("shmat");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        shmem[i] = rand() % 10;
    }

    printf("Dijete: Generirao niz znamenaka.\n");

    if (shmdt(shmem) == -1) {
        perror("shmdt");
        exit(1);
    }
}

void printNumber(int shmid, int n) {
    int* shmem = (int*)shmat(shmid, 0, 0);
    if (shmem == (int*)-1) {
        perror("shmat");
        exit(1);
    }

    printf("Roditelj: Ispisuje niz znamenaka: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", shmem[i]);
    }
    printf("\n");

    if (shmdt(shmem) == -1) {
        perror("shmdt");
        exit(1);
    }
}

int main() {
    int shmid;
    key_t key = IPC_PRIVATE;
    int n = 10; // broj znamenaka niza

    // Kreiranje dijeljene memorije
    shmid = shmget(key, MAX_SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Fork procesa
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Dijete
        generateNumber(shmid, n);
    } else {
        // Roditelj
        wait(NULL);
        printNumber(shmid, n);

        // Oslobađanje dijeljene memorije
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}
