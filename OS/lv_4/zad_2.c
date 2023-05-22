#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    // Stvaramo novi proces dijete
    pid = fork();

    if (pid == -1) {
        // Provjera greške pri stvaranju procesa
        printf("Greška pri fork() pozivu.\n");
        return 1;
    } else if (pid == 0) {
        // Kod djeteta
        // Pokrećemo naredbu "ls" s opcijom "-l"
        execl("/bin/ls", "ls", "-l", NULL);
        // Ako execl() uspije, ovaj kod se neće izvršiti
        printf("Greška pri execl() pozivu.\n");
        exit(1);
    } else {
        // Kod roditelja
        // Čekamo završetak izvršavanja djetetovog procesa
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Dijete je završilo s izlaznim kodom: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Dijete je završilo zbog signala: %d\n", WTERMSIG(status));
        }
    }

    return 0;
}

gcc -o ls_example ls_example.c
