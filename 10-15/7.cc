/*

    Scrivi un programma che esegua le seguenti operazioni:
    - Somma ogni elemento del primo array con l'elemento corrispondente del secondo array, considerando quest'ultimo "girato"
    - Stampa il risultato di ogni somma in sequenza.

*/

#include <stdio.h>

#define DIM 15

int main() {
    int arr1[DIM] = {88, 76, 21, 72, -2, 24, 63, 101, 35, 100, 105, 81, 5, 33, 66};
    int arr2[DIM] = {45, 76, 100, 34, 10, 5, 81, 13, 48, 78, 34, 39, 89, 35, 27};

    for (int i = 0; i < DIM; i++) {
        arr1[i] += arr2[DIM - i - 1];
    }

    for (int i = 0; i < DIM; i++) {
        printf("%c", arr1[i]);  // cast implicito -> il compilatore si arrangia ad interpretare come può
    }
    printf("\n");

    return 0;
}