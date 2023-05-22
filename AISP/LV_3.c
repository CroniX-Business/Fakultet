#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int n;
    int m;
} Parametri;

int povrh(int n, int m) {
    if (m == 0 || m == n) {
        return 1;
    }
    else {
        return povrh(n - 1, m - 1) + povrh(n - 1, m);
    }
}

int povrh_iter(int n, int m) {
    Parametri* stog = malloc(sizeof(Parametri) * (n + 1));
    int top = 0;
    stog[top++] = (Parametri){ n, m };
    int result = 0;
    while (top > 0) {
        Parametri params = stog[--top];
        n = params.n;
        m = params.m;
        if (m == 0 || m == n) {
            result += 1;
        }
        else {
            stog[top++] = (Parametri){ n - 1, m - 1 };
            stog[top++] = (Parametri){ n - 1, m };
        }
    }
    free(stog);
    return result;
}

int main() {
    clock_t start, end;
    double time_used;

    int n = 30;
    int m = n / 2;

    start = clock();
    int result_rec = povrh(n, m);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Rekurzivna funkcija: %d (%f ms)\n", result_rec, time_used);

    start = clock();
    int result_iter = povrh_iter(n, m);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Funkcija sa stogom: %d (%f ms)\n", result_iter, time_used);

    return 0;
}
