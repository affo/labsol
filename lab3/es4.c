/*
 * Scrivere un programma che generi una matrice 3x3 inserendo dei
 * numeri progressivi in ogni cella, la stampi e poi la trasformi in una
 * matrice triangolare superiore avente come elementi le somme degli
 * elementi simmetrici rispetto alla diagonale principale.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 3
#define MAX_INCR 5

int main (void) {
    int m[N][N], i, j;
    int last = -1; // ci salvo l'ultimo numero generato

    // inizializzo il generatore random
    srand(time(0));

    // generazione
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = last + 1 + (rand() % MAX_INCR);
            last = m[i][j];
        }
    }

    // prima stampata
    printf("Matrice generata:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    // processing
    for (i = 0; i < N; i++) {
        // NB: j = i + 1
        for (j = i + 1; j < N; j++) {
            m[i][j] += m[j][i];
            m[j][i] = 0;
        }
    }

    // stampata finale
    printf("Matrice triangolare superiore:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
