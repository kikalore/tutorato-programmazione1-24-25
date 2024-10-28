#include <cstdlib>
#include <iostream>
using namespace std;

#define DIM 100
#define N 100

void stampArr(int *arr, int dim);

int main() {
    srand(time(NULL));

    // FASE 1 -> inizializzazione arr con valori compresi tra 0 e N

    int arr[DIM];

    for (int i = 0; i < DIM; ++i) {
        arr[i] = rand() % N;
    }

    stampArr(arr, DIM);

    // FASE 2 -> array di appoggio/supporto a 0

    int appoggio[N] = {0};

    // FASE 3 -> scorro incrementando appoggio

    for (int i = 0; i < DIM; ++i) {
        appoggio[arr[i]]++;
    }

    stampArr(appoggio, N);

    // FASE 4 -> stampa

    printf("[");
    for (int i = 0; i < N; ++i) {                // per ogni elemento in appoggio
        for (int j = 0; j < appoggio[i]; ++j) {  // stampa tante volte quanto appoggio[i]
            printf("%2d, ", i);                  // la posizione (i)
        }
    }
    printf("]\n\n");

    return 0;
}

void stampArr(int *arr, int dim) {
    printf("[");
    for (int i = 0; i < dim; ++i) {
        printf("%2d, ", arr[i]);
    }
    printf("]\n\n");
}