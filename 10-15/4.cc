
/*

  Dati in input tre interi positivi in tre variabili (n1, n2, n3), scrivere
  una funzione che riordini e stampi i numeri in ordine crescente.

  Bonus: Scrivere una funzione con passaggio per valore, una con passaggio
  per riferimento e una con passaggio per puntatore. Provare ad eseguire
  ognuna delle funzioni e capire cosa succede.

*/

#include <cstdlib>
#include <iostream>

using namespace std;

void printInOrdine(int n1, int n2, int n3) {
    if (n1 > n2) {
        int tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    if (n2 > n3) {
        int tmp = n2;
        n2 = n3;
        n3 = tmp;
    }

    if (n1 > n2) {
        int tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
}

// funzione con parametri per riferimento
void printInOrdine2(int &n1, int &n2, int &n3) {
    if (n1 > n2) {
        int tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    if (n2 > n3) {
        int tmp = n2;
        n2 = n3;
        n3 = tmp;
    }

    if (n1 > n2) {
        int tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
}

// funzione con parametri per puntatori
// NB: non sono stati scambiati i valori, solo gli indirizzi a tali valori
void printInOrdine3(int *n1, int *n2, int *n3) {
    if (*n1 > *n2) {
        int *tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    if (*n2 > *n3) {
        int *tmp = n2;
        n2 = n3;
        n3 = tmp;
    }

    if (*n1 > *n2) {
        int *tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
}

int main() {
    int n1, n2, n3;
    cout << "Inserisci tre numeri interi positivi: ";
    cin >> n1 >> n2 >> n3;

    printInOrdine(n1, n2, n3);
    cout << n1 << " " << n2 << " " << n3 << endl;

    printInOrdine2(n1, n2, n3);
    cout << n1 << " " << n2 << " " << n3 << endl;

    printInOrdine3(&n1, &n2, &n3);
    cout << n1 << " " << n2 << " " << n3 << endl;

    return 0;
}
