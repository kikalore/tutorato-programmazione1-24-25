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
