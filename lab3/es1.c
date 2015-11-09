/*
 * Scrivere un programma che richieda all'utente di riempire una matrice
 * 3 x 3 di interi, la stampi, sostituisca nella matrice ogni numero pari con
 * la sua metà e, infine, stampi la matrice così modificata.
 */

#include <stdio.h>
#define N 3

int main (void) {
    int m[N][N], i, j;

    // acquisizione
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento in posizione (%d, %d): ", i, j);
            scanf("%d%*c", &m[i][j]);
        }
    }

    // prima stampata
    printf("Matrice inserita:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    // processing
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (m[i][j] % 2 == 0) {
                // numero pari
                m[i][j] /= 2;
            }
        }
    }

    // ultima stampata
    printf("Matrice processata:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
