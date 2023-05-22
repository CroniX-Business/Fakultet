#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_DIGITS 5 // Maksimalan broj znamenki u broju

int main() {
    pid_t pid;
    int broj, i;
    char znamenke[MAX_DIGITS + 1]; // +1 za '\0' na kraju niza

    printf("Unesite broj u rasponu [1, 10000]: ");
    scanf("%d", &broj);

    // Provjera unesenog broja
    if (broj < 1 || broj > 10000) {
        printf("Uneseni broj nije u ispravnom rasponu.\n");
        return 1;
    }

    // Pretvaranje broja u string
    snprintf(znamenke, MAX_DIGITS + 1, "%d", broj);

    // Stvaramo novi proces dijete
    pid = fork();

    if (pid == -1) {
        // Provjera greške pri stvaranju procesa
        printf("Greška pri fork() pozivu.\n");
        return 1;
    } else if (pid == 0) {
        // Kod djeteta
        printf("Proces dijete rastavlja broj na znamenke: ");
        for (i = 0; i < MAX_DIGITS; i++) {
            printf("%c ", znamenke[i]);
        }
        printf("\n");
        exit(0);
    } else {
        // Kod roditelja
        // Čekamo završetak izvršavanja djetetovog procesa
        wait(NULL);
        printf("Proces roditelj je završio čekanje.\n");
    }

    return 0;
}

gcc -o broj_znamenke broj_znamenke.c
