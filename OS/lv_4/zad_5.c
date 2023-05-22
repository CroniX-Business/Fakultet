//1. Zombie

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        printf("Greška pri fork() pozivu.\n");
        return 1;
    } else if (pid == 0) {
        // Kod djeteta
        printf("Dijete: Ja sam dijete i završavam s radom.\n");
        exit(0);
    } else {
        // Kod roditelja
        printf("Roditelj: Ja sam roditelj i spavam 30 sekundi.\n");
        sleep(30); // Spavamo 30 sekundi kako bi dijete završilo s radom i postalo Zombie proces
        printf("Roditelj: Dijete je završilo s radom.\n");
    }

    return 0;
}


//2. Orphan

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        printf("Greška pri fork() pozivu.\n");
        return 1;
    } else if (pid == 0) {
        // Kod djeteta
        printf("Dijete: Ja sam dijete i spavam 30 sekundi.\n");
        sleep(30); // Spavamo 30 sekundi kako bi roditelj završio s radom i postao Orphan proces
        printf("Dijete: Roditelj je završio s radom.\n");
    } else {
        // Kod roditelja
        printf("Roditelj: Ja sam roditelj i završavam s radom.\n");
        exit(0);
    }

    return 0;
}
