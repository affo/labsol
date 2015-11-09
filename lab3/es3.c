/*
 * Scrivere un programma che richieda all'utente di riempire una matrice
 * 3 x 3 di interi, la stampi, sostituisca nella matrice ogni numero dispari
 * con il suo cubo e, infine, calcoli e stampi la media di tutti gli elementi
 * della matrice così modificata.
 */

#include <stdio.h>
#define N 3

int main (void) {
    int m[N][N], i, j;
    float avg = 0; // NB è float

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

    // processing 1: cubo degli elementi dispari
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (m[i][j] % 2 != 0) {
                // numero dispari
                m[i][j] *= m[i][j] * m[i][j]; // calcolo il cubo
            }
        }
    }

    // processing 2: media (lo posso fare unitamente a processing 1)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            avg += m[i][j];
        }
    }
    avg /= N * N;

    // stampata della media
    printf("La media degli elementi è %f\n", avg);

    return 0;
}
