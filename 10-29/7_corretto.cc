/*
Scrivere una procedura che

- riempia di 1 e 0 una matrice di dimensione 10x10,
- la stampi a video
- dica quanti gruppi di 1 in celle vicine ci sono. Due celle sono vicine se sono sulla stessa colonna o se sono sulla stessa riga.

```
[
  1,1,1,1,1,0,1
  0,1,1,1,1,0,0
  0,0,0,0,0,0,0
  1,0,1,1,1,1,1
  0,1,0,0,0,0,0
  1,1,1,1,1,1,1
  0,0,0,0,0,0,0
]
```

In questo caso ci sono 5 gruppi di 1. In alto a sinistra c'è un gruppo di nove 1, in altro a destra c'è un gruppo di un uno, al centro a sinistra c'è un gruppo di un uno, in centro a destra c'è un
gruppo di 5 uno, in basso c'è un gruppo di otto 1.

Bonus point per dire quali sono le dimensioni dei gruppi.


L'idea è di colorare ogni gruppo, ossia di associare ad ogni gruppo un id. Se il numero che sto controllando è zero, allora il suo id rimane lo stesso. Se invece fosse un 1, allora ci sono le seguenti
possibilità:
- Non ha altri vicini con un id già noto, allora è il primo 1 che incontro per quel gruppo e gli assegno un nuovo id
- Ha vicini con un id già noto, allora quello diventa il suo id
Per id s'intende una variabile numerica che partendo da due viene incrementata ogni volta che si incontra un nuovo gruppo
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

#define WIDTH 10
#define HEIGHT 10
#define PROBABILITY 50

int rec(bool** mat, int i, int j);

int main(void) {
    srand(time(NULL));

    bool** mat;

    // init matrix
    mat = new bool*[HEIGHT];
    for (size_t i = 0; i < HEIGHT; i++) {
        mat[i] = (bool*)calloc(WIDTH, sizeof(bool));
        for (size_t j = 0; j < WIDTH; j++) {
            if (rand() % 100 < PROBABILITY) {
                mat[i][j] = true;
            }
        }
    }

    // print initial state
    for (size_t i = 0; i < HEIGHT; i++) {
        for (size_t j = 0; j < WIDTH; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // finds regions
    int regionsAmt = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (mat[i][j]) {
                regionsAmt++;
                int groupDim = rec(mat, i, j);
                std::cout << regionsAmt << ": " << groupDim << " 1s" << std::endl;
            }
        }
    }

    if (regionsAmt == 0) {
        std::cout << "Non ci sono regioni." << std::endl;
    }

    for (int i = 0; i < HEIGHT; ++i) free(mat[i]);
    free(mat);

    return 0;
}

int rec(bool** mat, int i, int j) {
    if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH || !mat[i][j]) {
        return 0;
    }
    mat[i][j] = false;
    return 1 + rec(mat, i - 1, j) + rec(mat, i + 1, j) + rec(mat, i, j - 1) + rec(mat, i, j + 1);
}
