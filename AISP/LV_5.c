#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i) {
    int largest = i;  // Inicijalno pretpostavljamo da je najveći element korijen
    int left = 2 * i + 1;  // Lijevo dijete
    int right = 2 * i + 2;  // Desno dijete

    // Provjera je li lijevo dijete veće od korijena
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Provjera je li desno dijete veće od najvećeg elementa do sada
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Ako najveći element nije korijen, zamjenjujemo ih
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int* arr, int n) {
    // Stvaranje Max Heap-a
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Izdvajanje elemenata iz Max Heap-a jedan po jedan i premještanje na kraj polja
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    int n = 10000;  // Veličina polja

    // Generiranje polja slučajnih brojeva
    int* array = (int*)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }

    // Kopiranje polja za bubble sort
    int* array_bubble = (int*)malloc(n * sizeof(int));
    memcpy(array_bubble, array, n * sizeof(int));

    clock_t start, end;
    double cpu_time_used;

    // Heap sort
    start = clock();
    heap_sort(array, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Heap Sort: %.2f ms\n", cpu_time_used);

    // Bubble sort
    start = clock();
    bubble_sort(array_bubble, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Bubble Sort: %.2f ms\n", cpu_time_used);

    free(array);
    free(array_bubble);

    return 0;
}
