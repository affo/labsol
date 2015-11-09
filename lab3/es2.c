/*
 * Scrivere un programma che richieda all'utente di riempire una matrice
 * 3 x 3 di interi, la stampi, calcoli e stampi la media di tutti gli elementi
 * divisibili per 3 della matrice stessa.
 */

#include <stdio.h>
#define N 3
// uso una define per il divisore in modo da poterlo
// cambiare velocemente
#define DIV 3

int main (void) {
    int m[N][N], i, j;
    int no_div = 0; // ci salvo il numero di elementi divisibili per DIV
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

    // processing
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (m[i][j] % DIV == 0) {
                // numero divisibile per DIV
                avg += m[i][j];
                no_div++;
            }
        }
    }

    // stampata della media
    printf("La media degli elementi divisibili per %d è %f\n", DIV, avg / no_div);

    return 0;
}
