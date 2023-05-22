#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Stvaramo novi proces dijete
    pid = fork();

    if (pid == -1) {
        // Provjera greške pri stvaranju procesa
        printf("Greška pri fork() pozivu.\n");
        return 1;
    } else if (pid == 0) {
        // Kod djeteta
        printf("Dijete - PID: %d, PPID: %d\n", getpid(), getppid());
        printf("dijete\n");
    } else {
        // Kod roditelja
        printf("Roditelj - PID: %d, PPID: %d\n", getpid(), getppid());
        printf("roditelj\n");
    }

    return 0;
}

gcc -o fork_example fork_example.c
