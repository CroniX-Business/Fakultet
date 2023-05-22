#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int N = 1000000;
    int* V = (int*)malloc(N * sizeof(int));
    struct Node* head = NULL;

    srand(time(NULL));

    int dg = 500;
    int gg = 3000;
    int target = 7;

    clock_t start = clock();
    for (int i = 0; i < N; i++) {
        V[i] = dg + ((float)rand() / RAND_MAX) * (gg - dg);;
    }
    printf("Vrijeme potrebno za stvaranje niza: %f\n", (double)(clock() * 1000 / CLOCKS_PER_SEC) - start);

    start = clock();
    for (int i = N - 1; i >= 0; i--) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = V[i];
        newNode->next = head;
        head = newNode;
    }
    printf("Vrijeme potrebno za stvaranje liste: %f\n", (double)(clock() * 1000 / CLOCKS_PER_SEC) - start);

    start = clock();
    for (int i = 0; i < N; i++) {
        if (V[i] == target) {
            printf("Element %d pronadjen na poziciji %d u nizu.\n", target, i);
            break;
        }
    }
    printf("Vrijeme potrebno za pretragu niza: %f\n", (double)(clock() * 1000 / CLOCKS_PER_SEC) - start);

    start = clock();
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            printf("Element %d pronadjen u povezanom popisu.\n", target);
            break;
        }
        current = current->next;
    }
    printf("Vrijeme potrebno za pretragu povezanog popisa: %f\n", (double)(clock() * 1000 / CLOCKS_PER_SEC) - start);

    free(V);
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
