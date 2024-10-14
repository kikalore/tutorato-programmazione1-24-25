
/*

    Scrivere una funzione foldLeft:
    input: un array, un valore iniziale e l'indice corrente
    output: il massimo valore dell'array.

*/

#include <limits.h>  // Per INT_MIN
#include <stdio.h>

#define DIM 15

int foldLeft(int array[], int max_val, int index, int size) {  // cosa cambia tra (int *arr) e (int arr[])
    if (index == size) {                                       // Caso base: fine dell'array
        return max_val;
    }

    if (array[index] > max_val) {  // aggiornamento max_val
        max_val = array[index];
    }

    return foldLeft(array, max_val, index + 1, size);
}

int main() {
    int array[DIM] = {88, 76, 21, 72, -2, 24, 63, 101, 35, 100, 105, 81, 5, 33, 66};  // valori casuali

    int max_value = foldLeft(array, INT_MIN, 0, DIM);  // INT_MIN è il valore minimo che int può contenere

    printf("max_value: %d\n", max_value);

    return 0;
}
