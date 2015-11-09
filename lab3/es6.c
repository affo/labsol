/*
 * Scrivere un programma che costruisce una matrice 5x5 di interi e un
 * vettore di interi di lunghezza 5 e stampa 1 se esiste una riga o una
 * colonna o una diagonale che contiene tutti gli elementi del vettore nello
 * stesso ordine ma in qualsiasi dei due possibili ordini, 0 altrimenti.
 */

#include <stdio.h>
#define N 5

int main (void) {
    int a[N];
    int i, j;
    int stop, stop_rev, found;

    /*
    int m[N][N];
    // acquisizione matrice
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento in posizione (%d, %d): ", i, j);
            scanf("%d%*c", &m[i][j]);
        }
    }
    */

    int m[N][N] = {
        {1, 11, 3, 5, -1},
        {4, -10, 8, 8, 3},
        {9, 9, 10, 1, 2},
        {42, 4, 2, 2, 1},
        {4, -10, 8, -1, 0}
    };

    // stampata matrice
    printf("Matrice inserita:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    // acquisizione vettore
    for (i = 0; i < N; i++) {
            printf("Elemento %d/%d vettore da trovare: ", i, N - 1);
            scanf("%d%*c", &a[i]);
    }


    // processing

    found = 0;

    // check diagonale principale
    // normale
    if (!found) {
        stop = 0;
        stop_rev = 0;
        for (i = 0; i < N && !(stop && stop_rev); i++) {
            if (!stop && m[i][i] != a[i]) {
                stop = 1;
            }
            if (!stop_rev && m[i][i] != a[N - i - 1]) {
                stop_rev = 1;
            }
        }

        // l'abbiamo trovato, se NON ci
        // siamo fermati nel caso normale
        // OPPURE nel caso reverse
        found = !stop || !stop_rev;
    }


    // check diagonale secondaria
    if (!found) {
        stop = 0;
        stop_rev = 0;
        for (i = 0; i < N && !(stop && stop_rev); i++) {
            if (!stop && m[i][N - i - 1] != a[i]) {
                stop = 1;
            }
            if (!stop_rev && m[i][N - i - 1] != a[N - i - 1]) {
                stop_rev = 1;
            }
        }

        found = !stop || !stop_rev;
    }


    // check per righe
    for (i = 0; i < N && !found; i++) {
        stop = 0;
        stop_rev = 0;
        for (j = 0; j < N && !(stop && stop_rev); j++) {
            if (!stop && m[i][j] != a[j]) {
                stop = 1;
            }
            if (!stop_rev && m[i][j] != a[N - j - 1]) {
                stop_rev = 1;
            }
        }

        found = !stop || !stop_rev;
    }

    // check per colonne
    for (j = 0; j < N && !found; j++) {
        stop = 0;
        stop_rev = 0;
        for (i = 0; i < N && !(stop && stop_rev); i++) {
            if (!stop && m[i][j] != a[i]) {
                stop = 1;
            }
            if (!stop_rev && m[i][j] != a[N - i - 1]) {
                stop_rev = 1;
            }
        }

        found = !stop || !stop_rev;
    }

    // ultima stampata
    printf("\n%d\n", found);

    return 0;
}
